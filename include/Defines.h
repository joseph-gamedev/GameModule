#pragma once

#define SAFEDESTROY(ptr) if(ptr) ptr->Destroy(); delete ptr; ptr = nullptr;