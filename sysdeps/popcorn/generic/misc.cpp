#include <mlibc/all-sysdeps.hpp>

namespace [[gnu::visibility("hidden")]] Log {
	enum level_t { OFF = -1, CRITICAL, WARNING, INFO, DEBUG, TRACE };

	void log(level_t level, const char *message, const char *file_name, int line, const char *func_name, ...);
};   // namespace Log

namespace mlibc {
	void sys_libc_log(const char *message) {
		__asm__ volatile("int3");
		//Log::log(Log::WARNING, "mlibc log: %s", "unknown", -1, "unknown", message);
	}

	[[noreturn]] void sys_libc_panic() {
		sys_libc_log("mlibc panic");
		__asm__ volatile("ud2");
	}

	int sys_tcb_set(void *pointer) {
		sys_libc_log("mlibc tcb_set");
		return -1;
	}

	int sys_futex_wait(int *pointer, int expected, const struct timespec *time) {
		sys_libc_log("mlibc futex_wait");
		return -1;
	}

	int sys_futex_wake(int *pointer) {
		sys_libc_log("mlibc futex_wake");
		return -1;
	}

	int sys_anon_allocate(size_t size, void **pointer) {
		sys_libc_log("mlibc anon_allocate");
		return -1;
	}

	int sys_anon_free(void *pointer, size_t size) {
		sys_libc_log("mlibc anon_free");
		return -1;
	}

	int sys_open(const char *pathname, int flags, mode_t mode, int *fd) {
		sys_libc_log("mlibc open");
		return -1;
	}

	int sys_read(int fd, void *buf, size_t count, ssize_t *bytes_read) {
		sys_libc_log("mlibc read");
		return -1;
	}

	int sys_write(int fd, const void *buf, size_t count, ssize_t *bytes_written) {
		sys_libc_log("mlibc write");
		return -1;
	}

	int sys_seek(int fd, off_t offset, int whence, off_t *new_offset) {
		sys_libc_log("mlibc seek");
		return -1;
	}

	int sys_close(int fd) {
		sys_libc_log("mlibc close");
		return -1;
	}

	// MUST ZERO CONTENTS
	int sys_vm_map(void *hint, size_t size, int prot, int flags, int fd, off_t offset, void **window) {
		sys_libc_log("mlibc vm_map");
		return -1;
	}

	int sys_vm_unmap(void *pointer, size_t size) {
		sys_libc_log("mlibc vm_unmap");
		return -1;
	}

	[[noreturn]] void sys_exit(int status)  {
		sys_libc_log("mlibc exit");
		__asm__ volatile("ud2");
	}

	int sys_clock_get(int clock, time_t *secs, long *nanos) {
		sys_libc_log("mlibc clock_get");
		return -1;
	}
}
