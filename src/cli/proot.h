/* This file is automatically generated from the documentation. EDIT AT YOUR OWN RISK. */

#ifndef PROOT_CLI_H
#define PROOT_CLI_H

#ifndef VERSION
#define VERSION "3.2.2"
#endif

static char *recommended_bindings[] = {
	"/etc/host.conf",
	"/etc/hosts",
	"/etc/hosts.equiv",
	"/etc/mtab",
	"/etc/netgroup",
	"/etc/networks",
	"/etc/passwd",
	"/etc/group",
	"/etc/nsswitch.conf",
	"/etc/resolv.conf",
	"/etc/localtime",
	"/dev/",
	"/sys/",
	"/proc/",
	"/tmp/",
	"$HOME",
	"*path*",
	NULL,
};

static int handle_option_r(Tracee *tracee, const Cli *cli, char *value);
static int handle_option_b(Tracee *tracee, const Cli *cli, char *value);
static int handle_option_q(Tracee *tracee, const Cli *cli, char *value);
static int handle_option_w(Tracee *tracee, const Cli *cli, char *value);
static int handle_option_v(Tracee *tracee, const Cli *cli, char *value);
static int handle_option_V(Tracee *tracee, const Cli *cli, char *value);
static int handle_option_h(Tracee *tracee, const Cli *cli, char *value);
static int handle_option_k(Tracee *tracee, const Cli *cli, char *value);
static int handle_option_0(Tracee *tracee, const Cli *cli, char *value);
static int handle_option_R(Tracee *tracee, const Cli *cli, char *value);
static int handle_option_B(Tracee *tracee, const Cli *cli, char *value);
static int handle_option_Q(Tracee *tracee, const Cli *cli, char *value);

static int pre_initialize_bindings(Tracee *, const Cli *, size_t, char *const *, size_t);
static int post_initialize_command(Tracee *, const Cli *, size_t, char *const *, size_t);

static Cli proot_cli = {
	.version  = VERSION,
	.name     = "proot",
	.subtitle = "chroot, mount --bind, and binfmt_misc without privilege/setup",
	.synopsis = "proot [option] ... [command]",
	.colophon = "Visit http://proot.me for help, bug reports, suggestions, patchs, ...\n\
Copyright (C) 2013 STMicroelectronics, licensed under GPL v2 or later.",
	.logo = "\
 _____ _____              ___\n\
|  __ \\  __ \\_____  _____|   |_\n\
|   __/     /  _  \\/  _  \\    _|\n\
|__|  |__|__\\_____/\\_____/\\____|",

	.pre_initialize_bindings = pre_initialize_bindings,
	.post_initialize_command = post_initialize_command,

	.options = {
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-r", .separator = ' ', .value = "path" },
		{ .name = "--rootfs", .separator = '=', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_r,
	  .description = "Use *path* as the new guest root file-system, default is /.",
	  .detail = "\tThe specified path typically contains a Linux distribution where\n\
\tall new programs will be confined.  The default rootfs is /\n\
\twhen none is specified, this makes sense when the bind mechanism\n\
\tis used to relocate host files and directories, see the -b\n\
\toption and the Examples section for details.\n\
\t\n\
\tIt is recommended to use the -R option instead.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-b", .separator = ' ', .value = "path" },
		{ .name = "--bind", .separator = '=', .value = "path" },
		{ .name = "-m", .separator = ' ', .value = "path" },
		{ .name = "--mount", .separator = '=', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_b,
	  .description = "Make the content of *path* accessible in the guest rootfs.",
	  .detail = "\tThis option makes any file or directory of the host rootfs\n\
\taccessible in the confined environment just as if it were part of\n\
\tthe guest rootfs.  By default the host path is bound to the same\n\
\tpath in the guest rootfs but users can specify any other location\n\
\twith the syntax: -b *host_path*:*guest_location*.  If the\n\
\tguest location is a symbolic link, it is dereferenced to ensure\n\
\tthe new content is accessible through all the symbolic links that\n\
\tpoint to the overlaid content.  In most cases this default\n\
\tbehavior shouldn't be a problem, although it is possible to\n\
\texplicitly not dereference the guest location by appending it the\n\
\t! character: -b *host_path*:*guest_location!*.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-q", .separator = ' ', .value = "command" },
		{ .name = "--qemu", .separator = '=', .value = "command" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_q,
	  .description = "Execute guest programs through QEMU as specified by *command*.",
	  .detail = "\tEach time a guest program is going to be executed, PRoot inserts\n\
\tthe QEMU user-mode command in front of the initial request.\n\
\tThat way, guest programs actually run on a virtual guest CPU\n\
\temulated by QEMU user-mode.  The native execution of host programs\n\
\tis still effective and the whole host rootfs is bound to\n\
\t/host-rootfs in the guest environment.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-w", .separator = ' ', .value = "path" },
		{ .name = "--pwd", .separator = '=', .value = "path" },
		{ .name = "--cwd", .separator = '=', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_w,
	  .description = "Set the initial working directory to *path*.",
	  .detail = "\tSome programs expect to be launched from a given directory but do\n\
\tnot perform any chdir by themselves.  This option avoids the\n\
\tneed for running a shell and then entering the directory manually.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-v", .separator = ' ', .value = "value" },
		{ .name = "--verbose", .separator = '=', .value = "value" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_v,
	  .description = "Set the level of debug information to *value*.",
	  .detail = "\tThe higher the integer value is, the more detailled debug\n\
\tinformation is printed to the standard error stream.  A negative\n\
\tvalue makes PRoot quiet except on fatal errors.",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-V", .separator = '\0', .value = NULL },
		{ .name = "--version", .separator = '\0', .value = NULL },
		{ .name = "--about", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_V,
	  .description = "Print version, copyright, license and contact, then exit.",
	  .detail = "",
	},
	{ .class = "Regular options",
	  .arguments = {
		{ .name = "-h", .separator = '\0', .value = NULL },
		{ .name = "--help", .separator = '\0', .value = NULL },
		{ .name = "--usage", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_h,
	  .description = "Print the version and the command-line usage, then exit.",
	  .detail = "",
	},
	{ .class = "Extension options",
	  .arguments = {
		{ .name = "-k", .separator = ' ', .value = "string" },
		{ .name = "--kernel-release", .separator = '=', .value = "string" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_k,
	  .description = "Set the kernel release and compatibility level to *string*.",
	  .detail = "\tIf a program is run on a kernel older than the one expected by its\n\
\tGNU C library, the following error is reported: \"FATAL: kernel too\n\
\told\".  To be able to run such programs, PRoot can emulate some of\n\
\tthe features that are available in the kernel release specified by\n\
\t*string* but that are missing in the current kernel.",
	},
	{ .class = "Extension options",
	  .arguments = {
		{ .name = "-0", .separator = '\0', .value = NULL },
		{ .name = "--root-id", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_0,
	  .description = "Force some syscalls to behave as if executed by \"root\".",
	  .detail = "\tSome programs will refuse to work if they are not run with \"root\"\n\
\tprivileges, even if there is no technical reason for that.  This\n\
\tis typically the case with package managers.  This option allows\n\
\tusers to bypass this kind of limitation by faking the user/group\n\
\tidentity, and by faking the success of some operations like\n\
\tchanging the ownership of files, changing the root directory to\n\
\t/, ...  Note that this option is quite limited compared to\n\
\tfakeroot.",
	},
	{ .class = "Alias options",
	  .arguments = {
		{ .name = "-R", .separator = ' ', .value = "path" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_R,
	  .description = "Alias: -r *path* + a couple of recommended -b.",
	  .detail = "\tPrograms isolated in *path*, a guest rootfs, might still need to\n\
\taccess information about the host system, as it is illustrated in\n\
\tthe Examples section of the manual.  These host information\n\
\tare typically: user/group definition, network setup, run-time\n\
\tinformation, users' files, ...  On all Linux distributions, they\n\
\tall lie in a couple of host files and directories that are\n\
\tautomatically bound by this option:\n\
\t\n\
\t    * /etc/host.conf\n\
\t    * /etc/hosts\n\
\t    * /etc/hosts.equiv\n\
\t    * /etc/mtab\n\
\t    * /etc/netgroup\n\
\t    * /etc/networks\n\
\t    * /etc/passwd\n\
\t    * /etc/group\n\
\t    * /etc/nsswitch.conf\n\
\t    * /etc/resolv.conf\n\
\t    * /etc/localtime\n\
\t    * /dev/\n\
\t    * /sys/\n\
\t    * /proc/\n\
\t    * /tmp/\n\
\t    * $HOME",
	},
	{ .class = "Alias options",
	  .arguments = {
		{ .name = "-B", .separator = '\0', .value = NULL },
		{ .name = "-M", .separator = '\0', .value = NULL },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_B,
	  .description = "obsolete, use -R instead.",
	  .detail = "",
	},
	{ .class = "Alias options",
	  .arguments = {
		{ .name = "-Q", .separator = ' ', .value = "command" },
		{ .name = NULL, .separator = '\0', .value = NULL } },
	  .handler = handle_option_Q,
	  .description = "obsolete, use -q and -R instead.",
	  .detail = "",
	},
	{0},
	},
};

#endif /* PROOT_CLI_H */
