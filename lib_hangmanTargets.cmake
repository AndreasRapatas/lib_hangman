include(GNUInstallDirs)
install(TARGETS JSONUtils
	EXPORT lib_hangman-export
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

