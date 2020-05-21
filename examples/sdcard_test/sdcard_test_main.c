#include <sdk/config.h>
#include <stdio.h>
#include <time.h>

#define BLOCK_SIZE 4096

const int ITERATION = 2621; // 44;
const char *TESTFILE_PATH = "/mnt/sd0/testfile";
static char block[BLOCK_SIZE];

void prepare_block(void) {
  for (int i = 0; i < BLOCK_SIZE; ++i) {
    block[i] = (char)(i % 256);
  }
}

void append_block(int sector_size, FILE *fp) {
  fwrite(block, sector_size, BLOCK_SIZE / sector_size, fp);
}

void print_elapsed_time(struct timespec *time_start, struct timespec *time_end) {
  if (time_end->tv_nsec > time_start->tv_nsec) {
    printf("Time elapsed: %ld.%09ld\n",
     time_end->tv_sec - time_start->tv_sec,
     time_end->tv_nsec - time_start->tv_nsec);
  }
  else {
    printf("Time elapsed: %ld.%09ld\n",
     time_end->tv_sec - time_start->tv_sec - 1,
     1000000000L + time_end->tv_nsec - time_start->tv_nsec);
  }
}

long elapsed_msec(struct timespec *time_start, struct timespec *time_end) {
  if (time_end->tv_nsec > time_start->tv_nsec) {
    return (time_end->tv_sec - time_start->tv_sec) * 1000 + (time_end->tv_nsec - time_start->tv_nsec) / 1000000;
  }
  else {
    return (time_end->tv_sec - time_start->tv_sec - 1) * 1000 + (1000000000L + time_end->tv_nsec - time_start->tv_nsec) / 1000000;
  }
}

int test_sd_write(void) {
  struct timespec time_start, time_end;
  long total_bytes = BLOCK_SIZE * ITERATION;

  prepare_block();
  FILE *fp = fopen(TESTFILE_PATH, "wb+");
  if (!fp) {
    printf("Failed to open file for writing: %s\n", TESTFILE_PATH);
    return 1;
  }
  printf("Writing block size = %d, count=%d, total of %ld bytes.\n", BLOCK_SIZE, ITERATION, total_bytes);
  clock_gettime(CLOCK_MONOTONIC, &time_start);

  for (int i = 0; i < ITERATION; ++i) {
    append_block(2048, fp);
  }
  clock_gettime(CLOCK_MONOTONIC, &time_end);

  fclose(fp);
  long ms = elapsed_msec(&time_start, &time_end);
  printf("WRITE: %.0f bytes/s (%ldms)\n", (total_bytes * 1000.0 / ms), ms);
  return 0;
}

int test_sd_read(void) {
  struct timespec time_start, time_end;
  long bytes_total_read = 0;
  int blocks_read = 0;

  FILE *fp = fopen(TESTFILE_PATH, "rb");
  if (!fp) {
    printf("Failed to open file for reading: %s\n", TESTFILE_PATH);
    return 1;
  }
  clock_gettime(CLOCK_MONOTONIC, &time_start);

  while ((blocks_read = fread(block, BLOCK_SIZE, 1, fp)) != 0) {
    bytes_total_read += blocks_read * BLOCK_SIZE;
  }
  clock_gettime(CLOCK_MONOTONIC, &time_end);

  fclose(fp);
  long ms = elapsed_msec(&time_start, &time_end);
  printf("READ: %.0f bytes/s (%ldms)\n", (bytes_total_read * 1000.0 / ms), ms);
  return 0;
}

#ifdef CONFIG_BUILD_KERNEL
int main(int argc, FAR char *argv[])
#else
int sdcard_test_main(int argc, char *argv[])
#endif
{
  if (test_sd_write() != 0) {
    return 1;
  }
  if (test_sd_read() != 0) {
    return 1;
  }
  return 0;
}

