/**
* \file Inline.h
* \brief Inline functions and templates
* \details This contains templates and prototypes to create inline components.
* \author Corbin Matschull
* \version 2
* \date Aug 31. 2015
* \pre Make sure you have GNU GCC or LLVM to compile, BSD or VCC won't compile.
* \throws CANNOT_CREATE_COMPONENT_EXCEPTION
*/
#include <Windows.h>
#include <allocators>

// ==========================================
// ------------------------------------------
//      INLINE TEMPLATES

/// \brief Creates virtual allocator for hash sets
template<class T, class Allocator = std::allocator<T>>
class forwardIdem;

/// \brief  Creates atomic type for hash sets
template<class T, class ForwardAtomic>
class AtomicSet;

