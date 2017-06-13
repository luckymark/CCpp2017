
#define BOOK_PP_CAT_IMPL(a, b) a ## b
#define BOOK_PP_CAT(a, b) BOOK_PP_CAT_IMPL(a, b)
#define BOOK_ID(identifier) BOOK_PP_CAT(auroraDetail_, identifier)
#define BOOK_LINE_ID(identifier) BOOK_PP_CAT(BOOK_ID(identifier), __LINE__)

#define FOREACH(declaration, container)																											\
	if (bool BOOK_LINE_ID(broken) = false) {} else																								\
	for (auto BOOK_LINE_ID(itr) = (container).begin(); BOOK_LINE_ID(itr) != (container).end() && !BOOK_LINE_ID(broken); ++BOOK_LINE_ID(itr))	\
	if (bool BOOK_LINE_ID(passed) = false) {} else																								\
	if (BOOK_LINE_ID(broken) = true, false) {} else																								\
	for (declaration = *BOOK_LINE_ID(itr); !BOOK_LINE_ID(passed); BOOK_LINE_ID(passed) = true, BOOK_LINE_ID(broken) = false)


