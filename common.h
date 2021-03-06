#ifndef __COMMON_H__
#define __COMMON_H__

#ifdef WX_PRECOMP
#include <wx/wxprec.h>
#else
#include <wx/wx.h>
#endif

#ifdef _WIN32
const bool IS_WINDOWS = true;
#else
const bool IS_WINDOWS = false;
#endif


//============================================================================
// Constantes
//============================================================================

const int MEM_SIZE    = 1 << 16;
const int BORDER_SIZE = 8;

//============================================================================
// Tipos
//============================================================================

using Byte = uint8_t;
using Word = uint16_t;

//============================================================================
// IDs
//============================================================================

enum {
    ID_OpenFile = 1,

    ID_DataTable,
    ID_ProgramTable,

    ID_DataTextControl,
    ID_ProgramTextControl,
};


#endif // __COMOON_H__
