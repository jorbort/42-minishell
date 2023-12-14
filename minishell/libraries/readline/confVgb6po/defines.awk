BEGIN {
D["PACKAGE_NAME"]=" \"readline\""
D["PACKAGE_TARNAME"]=" \"readline\""
D["PACKAGE_VERSION"]=" \"8.2\""
D["PACKAGE_STRING"]=" \"readline 8.2\""
D["PACKAGE_BUGREPORT"]=" \"bug-readline@gnu.org\""
D["PACKAGE_URL"]=" \"\""
D["HAVE_STDIO_H"]=" 1"
D["HAVE_STDLIB_H"]=" 1"
D["HAVE_STRING_H"]=" 1"
D["HAVE_INTTYPES_H"]=" 1"
D["HAVE_STDINT_H"]=" 1"
D["HAVE_STRINGS_H"]=" 1"
D["HAVE_SYS_STAT_H"]=" 1"
D["HAVE_SYS_TYPES_H"]=" 1"
D["HAVE_UNISTD_H"]=" 1"
D["HAVE_WCHAR_H"]=" 1"
D["STDC_HEADERS"]=" 1"
D["_ALL_SOURCE"]=" 1"
D["_DARWIN_C_SOURCE"]=" 1"
D["_GNU_SOURCE"]=" 1"
D["_HPUX_ALT_XOPEN_SOCKET_API"]=" 1"
D["_NETBSD_SOURCE"]=" 1"
D["_OPENBSD_SOURCE"]=" 1"
D["_POSIX_PTHREAD_SEMANTICS"]=" 1"
D["__STDC_WANT_IEC_60559_ATTRIBS_EXT__"]=" 1"
D["__STDC_WANT_IEC_60559_BFP_EXT__"]=" 1"
D["__STDC_WANT_IEC_60559_DFP_EXT__"]=" 1"
D["__STDC_WANT_IEC_60559_FUNCS_EXT__"]=" 1"
D["__STDC_WANT_IEC_60559_TYPES_EXT__"]=" 1"
D["__STDC_WANT_LIB_EXT2__"]=" 1"
D["__STDC_WANT_MATH_SPEC_FUNCS__"]=" 1"
D["_TANDEM_SOURCE"]=" 1"
D["__EXTENSIONS__"]=" 1"
D["PROTOTYPES"]=" 1"
D["__PROTOTYPES"]=" 1"
D["HAVE_DIRENT_H"]=" 1"
D["HAVE_FCNTL"]=" 1"
D["HAVE_GETTIMEOFDAY"]=" 1"
D["HAVE_KILL"]=" 1"
D["HAVE_LSTAT"]=" 1"
D["HAVE_PSELECT"]=" 1"
D["HAVE_READLINK"]=" 1"
D["HAVE_SELECT"]=" 1"
D["HAVE_SETITIMER"]=" 1"
D["HAVE_FNMATCH"]=" 1"
D["HAVE_MEMMOVE"]=" 1"
D["HAVE_PUTENV"]=" 1"
D["HAVE_SETENV"]=" 1"
D["HAVE_SETLOCALE"]=" 1"
D["HAVE_STRCASECMP"]=" 1"
D["HAVE_STRPBRK"]=" 1"
D["HAVE_SYSCONF"]=" 1"
D["HAVE_TCGETATTR"]=" 1"
D["HAVE_VSNPRINTF"]=" 1"
D["HAVE_ISASCII"]=" 1"
D["HAVE_ISXDIGIT"]=" 1"
D["HAVE_GETPWENT"]=" 1"
D["HAVE_GETPWNAM"]=" 1"
D["HAVE_GETPWUID"]=" 1"
D["HAVE_CHOWN"]=" 1"
D["HAVE_STRCOLL"]=" 1"
D["HAVE_FCNTL_H"]=" 1"
D["HAVE_UNISTD_H"]=" 1"
D["HAVE_STDLIB_H"]=" 1"
D["HAVE_STDARG_H"]=" 1"
D["HAVE_STDBOOL_H"]=" 1"
D["HAVE_STRING_H"]=" 1"
D["HAVE_STRINGS_H"]=" 1"
D["HAVE_LIMITS_H"]=" 1"
D["HAVE_LOCALE_H"]=" 1"
D["HAVE_PWD_H"]=" 1"
D["HAVE_MEMORY_H"]=" 1"
D["HAVE_TERMCAP_H"]=" 1"
D["HAVE_TERMIOS_H"]=" 1"
D["HAVE_SYS_IOCTL_H"]=" 1"
D["HAVE_SYS_SELECT_H"]=" 1"
D["HAVE_SYS_TIME_H"]=" 1"
D["HAVE_SYS_FILE_H"]=" 1"
D["HAVE_POSIX_SIGNALS"]=" 1"
D["HAVE_POSIX_SIGSETJMP"]=" 1"
D["HAVE_LSTAT"]=" 1"
D["HAVE_GETPW_DECLS"]=" 1"
D["HAVE_INTTYPES_H"]=" 1"
D["TIOCSTAT_IN_SYS_IOCTL"]=" 1"
D["FIONREAD_IN_SYS_IOCTL"]=" 1"
D["STRUCT_WINSIZE_IN_SYS_IOCTL"]=" 1"
D["HAVE_STRUCT_DIRENT_D_INO"]=" 1"
D["HAVE_STRUCT_DIRENT_D_INO"]=" 1"
D["HAVE_STRUCT_DIRENT_D_FILENO"]=" 1"
D["HAVE_STRUCT_DIRENT_D_FILENO"]=" 1"
D["HAVE_TIMEVAL"]=" 1"
D["HAVE_DECL_AUDIT_USER_TTY"]=" 0"
D["HAVE_LANGINFO_CODESET"]=" 1"
D["HAVE_WCTYPE_H"]=" 1"
D["HAVE_WCHAR_H"]=" 1"
D["HAVE_LANGINFO_H"]=" 1"
D["HAVE_MBRLEN"]=" 1"
D["HAVE_MBSNRTOWCS"]=" 1"
D["HAVE_MBSRTOWCS"]=" 1"
D["HAVE_WCRTOMB"]=" 1"
D["HAVE_WCSCOLL"]=" 1"
D["HAVE_WCSDUP"]=" 1"
D["HAVE_WCWIDTH"]=" 1"
D["HAVE_WCTYPE"]=" 1"
D["HAVE_WCSWIDTH"]=" 1"
D["HAVE_MBRTOWC"]=" 1"
D["HAVE_MBSTATE_T"]=" 1"
D["HAVE_ISWLOWER"]=" 1"
D["HAVE_ISWUPPER"]=" 1"
D["HAVE_TOWLOWER"]=" 1"
D["HAVE_TOWUPPER"]=" 1"
D["HAVE_ISWCTYPE"]=" 1"
D["HAVE_WCHAR_T"]=" 1"
D["HAVE_WCTYPE_T"]=" 1"
D["HAVE_WINT_T"]=" 1"
D["SIZEOF_WCHAR_T"]=" 4"
  for (key in D) D_is_set[key] = 1
  FS = ""
}
/^[\t ]*#[\t ]*(define|undef)[\t ]+[_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ][_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789]*([\t (]|$)/ {
  line = $ 0
  split(line, arg, " ")
  if (arg[1] == "#") {
    defundef = arg[2]
    mac1 = arg[3]
  } else {
    defundef = substr(arg[1], 2)
    mac1 = arg[2]
  }
  split(mac1, mac2, "(") #)
  macro = mac2[1]
  prefix = substr(line, 1, index(line, defundef) - 1)
  if (D_is_set[macro]) {
    # Preserve the white space surrounding the "#".
    print prefix "define", macro P[macro] D[macro]
    next
  } else {
    # Replace #undef with comments.  This is necessary, for example,
    # in the case of _POSIX_SOURCE, which is predefined and required
    # on some systems where configure will not decide to define it.
    if (defundef == "undef") {
      print "/*", prefix defundef, macro, "*/"
      next
    }
  }
}
{ print }
