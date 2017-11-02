#pragma once
//this is to safeguard against included the same header file multiple times in a file

//inside of common.h we want to link buttons.h so that whenever we include common.h
//we also include both ofMain.h and buttons.h
#include "ofMain.h"
#include "buttons.h"