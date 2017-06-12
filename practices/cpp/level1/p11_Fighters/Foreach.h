#ifndef FOREACH_H_
#define FOREACH_H_

// Preprocessor trick to allow nested loops
#define PP_CAT_IMPL(a, b) a ## b
#define PP_CAT(a, b) PP_CAT_IMPL(a, b)
#define ID(identifier) PP_CAT(auroraDetail_, identifier)
#define LINE_ID(identifier) PP_CAT(ID(identifier), __LINE__)


// Macro to emulate C++11 range-based for loop
// Instead of for (decl : range) you write FOREACH(decl, range) as in the following example
//
// std::vector<int> v = ...;
// FOREACH(int& i, v)
// {
//     i += 2;
// }
#define FOREACH(declaration, container)																											\
	if (bool LINE_ID(broken) = false) {} else																								\
	for (auto LINE_ID(itr) = (container).begin(); LINE_ID(itr) != (container).end() && !LINE_ID(broken); ++LINE_ID(itr))	\
	if (bool LINE_ID(passed) = false) {} else																								\
	if (LINE_ID(broken) = true, false) {} else																								\
	for (declaration = *LINE_ID(itr); !LINE_ID(passed); LINE_ID(passed) = true, LINE_ID(broken) = false)

#endif // FOREACH_H_
