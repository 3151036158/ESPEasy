#ifndef PLUGINSTRUCTS_P016_DATA_STRUCT_H
#define PLUGINSTRUCTS_P016_DATA_STRUCT_H

#include "../../_Plugin_Helper.h"
#include "../../ESPEasy_common.h"

#ifdef USES_P016

#define PLUGIN_016_DEBUG        // additional debug messages in the log

// bit definition in PCONFIG_LONG(0)
#define P016_BitAddNewCode  0   // Add automatically new code into Code of the command structure
#define P016_BitExecuteCmd  1   // Execute command if received code matches Code or AlternativeCode of the command structure

#define P16_Nlines 10           // The number of different lines which can be displayed - each line is 64 chars max
#define P16_Nchars 64           // max chars per command line
#define P16_Cchars 20           // max chars per code

typedef struct {
  char      Command[P16_Nchars] = { 0 };
  uint32_t  Code = 0; // received code (can be added automatically)
  uint32_t  AlternativeCode = 0;  // alternative code fpr the same command
} tCommandLines;

extern String uint64ToString(uint64_t input, uint8_t base);

struct P016_data_struct : public PluginTaskData_base {
public:
  P016_data_struct();

  void init(taskIndex_t taskIndex);
  void loadCommandLines(taskIndex_t taskIndex);
  void AddCode(uint32_t  Code);
  void ExecuteCode(uint32_t  Code);

  // CustomTaskSettings
  tCommandLines CommandLines[P16_Nlines]; // holds the CustomTaskSettings

  bool bCodeChanged = false;  // set if code has been added and CommandLines need to be saved (in PLUGIN_ONCE_A_SECOND)
};

#endif // ifdef USES_P016
#endif // ifndef PLUGINSTRUCTS_P016_DATA_STRUCT_H
