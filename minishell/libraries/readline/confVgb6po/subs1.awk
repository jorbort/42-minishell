BEGIN {
S["LTLIBOBJS"]=" ${LIBOBJDIR}mbschr$U.lo"
S["TERMCAP_PKG_CONFIG_LIB"]="termcap"
S["TERMCAP_LIB"]="-ltermcap"
S["LIBVERSION"]="8.2"
S["ARFLAGS"]="cr"
S["LOCAL_DEFS"]=""
S["LOCAL_LDFLAGS"]=""
S["LOCAL_CFLAGS"]=""
S["BUILD_DIR"]="/Users/juanantoniomartinezmorales/Desktop/42-minishell/minishell/libraries/readline"
S["EXAMPLES_INSTALL_TARGET"]="install-examples"
S["SHARED_INSTALL_TARGET"]="install-shared"
S["STATIC_INSTALL_TARGET"]="install-static"
S["SHARED_TARGET"]="shared"
S["STATIC_TARGET"]="static"
S["SHLIB_MINOR"]="2"
S["SHLIB_MAJOR"]="8"
S["SHLIB_LIBS"]="-lncurses"
S["SHLIB_DLLVERSION"]="$(SHLIB_MAJOR)"
S["SHLIB_LIBVERSION"]="$(SHLIB_MAJOR)$(SHLIB_MINOR).$(SHLIB_LIBSUFF)"
S["SHLIB_LIBSUFF"]="dylib"
S["SHLIB_LIBPREF"]="lib"
S["SHLIB_DOT"]="."
S["SHLIB_XLDFLAGS"]="-dynamiclib -install_name $(libdir)/`echo $@ | sed \"s:\\..*::\"`.$(SHLIB_MAJOR).$(SHLIB_LIBSUFF) -current_version $(SHLIB_MAJOR)$(SHLIB_MINOR) -compat"\
"ibility_version $(SHLIB_MAJOR)$(SHLIB_MINOR) -v"
S["SHLIB_STATUS"]="supported"
S["SHOBJ_STATUS"]="supported"
S["SHOBJ_LIBS"]=""
S["SHOBJ_XLDFLAGS"]=""
S["SHOBJ_LDFLAGS"]="-dynamiclib -dynamic -undefined dynamic_lookup "
S["SHOBJ_LD"]="${CC}"
S["SHOBJ_CFLAGS"]="-fno-common"
S["SHOBJ_CC"]="gcc"
S["LIBOBJS"]=" ${LIBOBJDIR}mbschr$U.o"
S["MAKE_SHELL"]="/bin/sh"
S["RANLIB"]="ranlib"
S["AR"]="ar"
S["INSTALL_DATA"]="${INSTALL} -m 644"
S["INSTALL_SCRIPT"]="${INSTALL}"
S["INSTALL_PROGRAM"]="${INSTALL}"
S["EGREP"]="/usr/bin/grep -E"
S["GREP"]="/usr/bin/grep"
S["CPP"]="gcc -E"
S["OBJEXT"]="o"
S["EXEEXT"]=""
S["ac_ct_CC"]="gcc"
S["CPPFLAGS"]=""
S["LDFLAGS"]=""
S["CFLAGS"]="-g -O2 -Wno-parentheses -Wno-format-security -Wno-tautological-constant-out-of-range-compare"
S["CC"]="gcc"
S["SET_MAKE"]=""
S["CROSS_COMPILE"]=""
S["BRACKETED_PASTE"]="-DBRACKETED_PASTE_DEFAULT=1"
S["host_os"]="darwin17.7.0"
S["host_vendor"]="apple"
S["host_cpu"]="x86_64"
S["host"]="x86_64-apple-darwin17.7.0"
S["build_os"]="darwin17.7.0"
S["build_vendor"]="apple"
S["build_cpu"]="x86_64"
S["build"]="x86_64-apple-darwin17.7.0"
S["target_alias"]=""
S["host_alias"]=""
S["build_alias"]=""
S["LIBS"]=""
S["ECHO_T"]=""
S["ECHO_N"]=""
S["ECHO_C"]="\\c"
S["DEFS"]="-DHAVE_CONFIG_H"
S["mandir"]="${datarootdir}/man"
S["localedir"]="${datarootdir}/locale"
S["libdir"]="${exec_prefix}/lib"
S["psdir"]="${docdir}"
S["pdfdir"]="${docdir}"
S["dvidir"]="${docdir}"
S["htmldir"]="${docdir}"
S["infodir"]="${datarootdir}/info"
S["docdir"]="${datarootdir}/doc/${PACKAGE_TARNAME}"
S["oldincludedir"]="/usr/include"
S["includedir"]="${prefix}/include"
S["runstatedir"]="${localstatedir}/run"
S["localstatedir"]="${prefix}/var"
S["sharedstatedir"]="${prefix}/com"
S["sysconfdir"]="${prefix}/etc"
S["datadir"]="${datarootdir}"
S["datarootdir"]="${prefix}/share"
S["libexecdir"]="${exec_prefix}/libexec"
S["sbindir"]="${exec_prefix}/sbin"
S["bindir"]="${exec_prefix}/bin"
S["program_transform_name"]="s,x,x,"
S["prefix"]="/usr/local"
S["exec_prefix"]="${prefix}"
S["PACKAGE_URL"]=""
S["PACKAGE_BUGREPORT"]="bug-readline@gnu.org"
S["PACKAGE_STRING"]="readline 8.2"
S["PACKAGE_VERSION"]="8.2"
S["PACKAGE_TARNAME"]="readline"
S["PACKAGE_NAME"]="readline"
S["PATH_SEPARATOR"]=":"
S["SHELL"]="/bin/sh"
  for (key in S) S_is_set[key] = 1
  FS = ""

}
{
  line = $ 0
  nfields = split(line, field, "@")
  substed = 0
  len = length(field[1])
  for (i = 2; i < nfields; i++) {
    key = field[i]
    keylen = length(key)
    if (S_is_set[key]) {
      value = S[key]
      line = substr(line, 1, len) "" value "" substr(line, len + keylen + 3)
      len += length(value) + length(field[++i])
      substed = 1
    } else
      len += 1 + keylen
  }

  print line
}

