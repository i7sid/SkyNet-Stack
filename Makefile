#
# OMNeT++/OMNEST Makefile for SkyNet
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out
#

# Name of target to be created (-o option)
TARGET = SkyNet$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I. \
    -Ibase \
    -Ibase/connectionManager \
    -Ibase/messages \
    -Ibase/modules \
    -Ibase/phyLayer \
    -Ibase/utils \
    -Ienvironment \
    -Iglider \
    -Iglider/application \
    -Iglider/mobility \
    -Iglider/radio \
    -Iglider/radio/mac \
    -Iglider/radio/phy \
    -Iglider/radio/utils \
    -Iresults \
    -Isimulation \
    -Isimulation/logfiles \
    -Isimulation/logfiles/20131104 \
    -Isimulation/logfiles/20131105 \
    -Isimulation/logfiles/20131111_1 \
    -Isimulation/logfiles/20131111_2 \
    -Isimulation/logfiles/20131112 \
    -Isimulation/logfiles/20131113_1 \
    -Isimulation/logfiles/20131113_2 \
    -Isimulation/logfiles/20131114 \
    -Isimulation/logfiles/20131115 \
    -Isimulation/logfiles/20131116 \
    -Isimulation/logfiles/20131117_1 \
    -Isimulation/logfiles/20131117_2 \
    -Isimulation/logfiles/20131118 \
    -Isimulation/logfiles/20131121 \
    -Isimulation/logfiles/2013BassanoTag1 \
    -Isimulation/results \
    -Isimulation/results/20131104 \
    -Isimulation/results/20131105 \
    -Isimulation/results/20131111_1 \
    -Isimulation/results/20131111_2 \
    -Isimulation/results/20131112 \
    -Isimulation/results/20131113_1 \
    -Isimulation/results/20131113_2 \
    -Isimulation/results/20131114 \
    -Isimulation/results/20131115 \
    -Isimulation/results/20131116 \
    -Isimulation/results/20131117_1 \
    -Isimulation/results/20131117_2 \
    -Isimulation/results/20131118 \
    -Isimulation/results/20131121

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS =

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = \
    $O/base/connectionManager/NicEntryDebug.o \
    $O/base/connectionManager/ChannelAccess.o \
    $O/base/connectionManager/ConnectionManager.o \
    $O/base/connectionManager/NicEntryDirect.o \
    $O/base/connectionManager/BaseConnectionManager.o \
    $O/base/modules/BaseMacLayer.o \
    $O/base/modules/BatteryAccess.o \
    $O/base/modules/BaseApplLayer.o \
    $O/base/modules/BaseMobility.o \
    $O/base/modules/BaseBattery.o \
    $O/base/modules/BaseModule.o \
    $O/base/modules/BaseWorldUtility.o \
    $O/base/modules/BaseLayer.o \
    $O/base/phyLayer/MappingBase.o \
    $O/base/phyLayer/MappingUtils.o \
    $O/base/phyLayer/Decider.o \
    $O/base/phyLayer/Signal.o \
    $O/base/phyLayer/BaseDecider.o \
    $O/base/phyLayer/ChannelState.o \
    $O/base/phyLayer/BasePhyLayer.o \
    $O/base/phyLayer/PhyUtils.o \
    $O/base/phyLayer/ChannelInfo.o \
    $O/base/utils/SimpleAddress.o \
    $O/base/utils/NetwToMacControlInfo.o \
    $O/base/utils/Coord.o \
    $O/environment/WindManager.o \
    $O/environment/Thermal.o \
    $O/environment/ThermalChildress.o \
    $O/environment/ThermalManager.o \
    $O/glider/application/GliderApplLayer.o \
    $O/glider/application/Transmission.o \
    $O/glider/application/PositionMessage.o \
    $O/glider/mobility/Position.o \
    $O/glider/mobility/GliderMobility.o \
    $O/glider/radio/mac/GliderMacLayer.o \
    $O/glider/radio/phy/GliderAnalogueModel.o \
    $O/glider/radio/phy/GliderDecider.o \
    $O/glider/radio/phy/GliderPhyLayer.o \
    $O/simulation/SimulationManager.o \
    $O/base/messages/AirFrame_m.o \
    $O/base/messages/BorderMsg_m.o \
    $O/base/messages/ChannelSenseRequest_m.o \
    $O/glider/application/GliderNetworkPkt_m.o \
    $O/glider/radio/mac/MacFrame_m.o

# Message files
MSGFILES = \
    base/messages/AirFrame.msg \
    base/messages/BorderMsg.msg \
    base/messages/ChannelSenseRequest.msg \
    glider/application/GliderNetworkPkt.msg \
    glider/radio/mac/MacFrame.msg

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f SkyNet SkyNet.exe libSkyNet.so libSkyNet.a libSkyNet.dll libSkyNet.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h
	$(Q)-rm -f base/*_m.cc base/*_m.h
	$(Q)-rm -f base/connectionManager/*_m.cc base/connectionManager/*_m.h
	$(Q)-rm -f base/messages/*_m.cc base/messages/*_m.h
	$(Q)-rm -f base/modules/*_m.cc base/modules/*_m.h
	$(Q)-rm -f base/phyLayer/*_m.cc base/phyLayer/*_m.h
	$(Q)-rm -f base/utils/*_m.cc base/utils/*_m.h
	$(Q)-rm -f environment/*_m.cc environment/*_m.h
	$(Q)-rm -f glider/*_m.cc glider/*_m.h
	$(Q)-rm -f glider/application/*_m.cc glider/application/*_m.h
	$(Q)-rm -f glider/mobility/*_m.cc glider/mobility/*_m.h
	$(Q)-rm -f glider/radio/*_m.cc glider/radio/*_m.h
	$(Q)-rm -f glider/radio/mac/*_m.cc glider/radio/mac/*_m.h
	$(Q)-rm -f glider/radio/phy/*_m.cc glider/radio/phy/*_m.h
	$(Q)-rm -f glider/radio/utils/*_m.cc glider/radio/utils/*_m.h
	$(Q)-rm -f results/*_m.cc results/*_m.h
	$(Q)-rm -f simulation/*_m.cc simulation/*_m.h
	$(Q)-rm -f simulation/logfiles/*_m.cc simulation/logfiles/*_m.h
	$(Q)-rm -f simulation/logfiles/20131104/*_m.cc simulation/logfiles/20131104/*_m.h
	$(Q)-rm -f simulation/logfiles/20131105/*_m.cc simulation/logfiles/20131105/*_m.h
	$(Q)-rm -f simulation/logfiles/20131111_1/*_m.cc simulation/logfiles/20131111_1/*_m.h
	$(Q)-rm -f simulation/logfiles/20131111_2/*_m.cc simulation/logfiles/20131111_2/*_m.h
	$(Q)-rm -f simulation/logfiles/20131112/*_m.cc simulation/logfiles/20131112/*_m.h
	$(Q)-rm -f simulation/logfiles/20131113_1/*_m.cc simulation/logfiles/20131113_1/*_m.h
	$(Q)-rm -f simulation/logfiles/20131113_2/*_m.cc simulation/logfiles/20131113_2/*_m.h
	$(Q)-rm -f simulation/logfiles/20131114/*_m.cc simulation/logfiles/20131114/*_m.h
	$(Q)-rm -f simulation/logfiles/20131115/*_m.cc simulation/logfiles/20131115/*_m.h
	$(Q)-rm -f simulation/logfiles/20131116/*_m.cc simulation/logfiles/20131116/*_m.h
	$(Q)-rm -f simulation/logfiles/20131117_1/*_m.cc simulation/logfiles/20131117_1/*_m.h
	$(Q)-rm -f simulation/logfiles/20131117_2/*_m.cc simulation/logfiles/20131117_2/*_m.h
	$(Q)-rm -f simulation/logfiles/20131118/*_m.cc simulation/logfiles/20131118/*_m.h
	$(Q)-rm -f simulation/logfiles/20131121/*_m.cc simulation/logfiles/20131121/*_m.h
	$(Q)-rm -f simulation/logfiles/2013BassanoTag1/*_m.cc simulation/logfiles/2013BassanoTag1/*_m.h
	$(Q)-rm -f simulation/results/*_m.cc simulation/results/*_m.h
	$(Q)-rm -f simulation/results/20131104/*_m.cc simulation/results/20131104/*_m.h
	$(Q)-rm -f simulation/results/20131105/*_m.cc simulation/results/20131105/*_m.h
	$(Q)-rm -f simulation/results/20131111_1/*_m.cc simulation/results/20131111_1/*_m.h
	$(Q)-rm -f simulation/results/20131111_2/*_m.cc simulation/results/20131111_2/*_m.h
	$(Q)-rm -f simulation/results/20131112/*_m.cc simulation/results/20131112/*_m.h
	$(Q)-rm -f simulation/results/20131113_1/*_m.cc simulation/results/20131113_1/*_m.h
	$(Q)-rm -f simulation/results/20131113_2/*_m.cc simulation/results/20131113_2/*_m.h
	$(Q)-rm -f simulation/results/20131114/*_m.cc simulation/results/20131114/*_m.h
	$(Q)-rm -f simulation/results/20131115/*_m.cc simulation/results/20131115/*_m.h
	$(Q)-rm -f simulation/results/20131116/*_m.cc simulation/results/20131116/*_m.h
	$(Q)-rm -f simulation/results/20131117_1/*_m.cc simulation/results/20131117_1/*_m.h
	$(Q)-rm -f simulation/results/20131117_2/*_m.cc simulation/results/20131117_2/*_m.h
	$(Q)-rm -f simulation/results/20131118/*_m.cc simulation/results/20131118/*_m.h
	$(Q)-rm -f simulation/results/20131121/*_m.cc simulation/results/20131121/*_m.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc base/*.cc base/connectionManager/*.cc base/messages/*.cc base/modules/*.cc base/phyLayer/*.cc base/utils/*.cc environment/*.cc glider/*.cc glider/application/*.cc glider/mobility/*.cc glider/radio/*.cc glider/radio/mac/*.cc glider/radio/phy/*.cc glider/radio/utils/*.cc results/*.cc simulation/*.cc simulation/logfiles/*.cc simulation/logfiles/20131104/*.cc simulation/logfiles/20131105/*.cc simulation/logfiles/20131111_1/*.cc simulation/logfiles/20131111_2/*.cc simulation/logfiles/20131112/*.cc simulation/logfiles/20131113_1/*.cc simulation/logfiles/20131113_2/*.cc simulation/logfiles/20131114/*.cc simulation/logfiles/20131115/*.cc simulation/logfiles/20131116/*.cc simulation/logfiles/20131117_1/*.cc simulation/logfiles/20131117_2/*.cc simulation/logfiles/20131118/*.cc simulation/logfiles/20131121/*.cc simulation/logfiles/2013BassanoTag1/*.cc simulation/results/*.cc simulation/results/20131104/*.cc simulation/results/20131105/*.cc simulation/results/20131111_1/*.cc simulation/results/20131111_2/*.cc simulation/results/20131112/*.cc simulation/results/20131113_1/*.cc simulation/results/20131113_2/*.cc simulation/results/20131114/*.cc simulation/results/20131115/*.cc simulation/results/20131116/*.cc simulation/results/20131117_1/*.cc simulation/results/20131117_2/*.cc simulation/results/20131118/*.cc simulation/results/20131121/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/base/connectionManager/BaseConnectionManager.o: base/connectionManager/BaseConnectionManager.cc \
	base/connectionManager/NicEntry.h \
	base/connectionManager/NicEntryDebug.h \
	base/connectionManager/NicEntryDirect.h \
	base/modules/BaseWorldUtility.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/connectionManager/ChannelAccess.o: base/connectionManager/ChannelAccess.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/ChannelAccess.h \
	base/connectionManager/NicEntry.h \
	base/modules/BaseBattery.h \
	base/modules/BaseMobility.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/BatteryAccess.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/miximkerneldefs.h
$O/base/connectionManager/ConnectionManager.o: base/connectionManager/ConnectionManager.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/ConnectionManager.h \
	base/connectionManager/NicEntry.h \
	base/modules/BaseWorldUtility.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/connectionManager/NicEntryDebug.o: base/connectionManager/NicEntryDebug.cc \
	base/connectionManager/ChannelAccess.h \
	base/connectionManager/NicEntry.h \
	base/connectionManager/NicEntryDebug.h \
	base/modules/BaseBattery.h \
	base/modules/BaseMobility.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/BatteryAccess.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/miximkerneldefs.h
$O/base/connectionManager/NicEntryDirect.o: base/connectionManager/NicEntryDirect.cc \
	base/connectionManager/ChannelAccess.h \
	base/connectionManager/NicEntry.h \
	base/connectionManager/NicEntryDirect.h \
	base/modules/BaseBattery.h \
	base/modules/BaseMobility.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/BatteryAccess.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/miximkerneldefs.h
$O/base/messages/AirFrame_m.o: base/messages/AirFrame_m.cc \
	base/messages/AirFrame_m.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/messages/BorderMsg_m.o: base/messages/BorderMsg_m.cc \
	base/messages/BorderMsg_m.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/messages/ChannelSenseRequest_m.o: base/messages/ChannelSenseRequest_m.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/phyLayer/ChannelState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/modules/BaseApplLayer.o: base/modules/BaseApplLayer.cc \
	base/modules/BaseApplLayer.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/BatteryAccess.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h
$O/base/modules/BaseBattery.o: base/modules/BaseBattery.cc \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/modules/BaseLayer.o: base/modules/BaseLayer.cc \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseModule.h \
	base/modules/BatteryAccess.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/PassedMessage.h \
	base/utils/miximkerneldefs.h
$O/base/modules/BaseMacLayer.o: base/modules/BaseMacLayer.cc \
	base/connectionManager/ChannelAccess.h \
	base/modules/AddressingInterface.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseMobility.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/BatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyControlInfo.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MacToNetwControlInfo.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	glider/radio/mac/MacFrame_m.h \
	glider/radio/mac/mac_types.h \
	glider/radio/utils/NetwToMacInfo.h
$O/base/modules/BaseMobility.o: base/modules/BaseMobility.cc \
	base/messages/BorderMsg_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseMobility.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/BatteryAccess.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/miximkerneldefs.h
$O/base/modules/BaseModule.o: base/modules/BaseModule.cc \
	base/modules/BaseModule.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/modules/BaseWorldUtility.o: base/modules/BaseWorldUtility.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/NicEntry.h \
	base/modules/BaseWorldUtility.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/modules/BatteryAccess.o: base/modules/BatteryAccess.cc \
	base/modules/BaseBattery.h \
	base/modules/BaseModule.h \
	base/modules/BatteryAccess.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/BaseDecider.o: base/phyLayer/BaseDecider.cc \
	base/messages/AirFrame_m.h \
	base/messages/ChannelSenseRequest_m.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/BasePhyLayer.o: base/phyLayer/BasePhyLayer.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/NicEntry.h \
	base/messages/ChannelSenseRequest_m.h \
	base/modules/BaseWorldUtility.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyControlInfo.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyToMacControlInfo.h \
	base/phyLayer/Signal_.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/ChannelInfo.o: base/phyLayer/ChannelInfo.cc \
	base/messages/AirFrame_m.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/ChannelState.o: base/phyLayer/ChannelState.cc \
	base/phyLayer/ChannelState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/Decider.o: base/phyLayer/Decider.cc \
	base/messages/ChannelSenseRequest_m.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/MappingBase.o: base/phyLayer/MappingBase.cc \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MappingBase.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/MappingUtils.o: base/phyLayer/MappingUtils.cc \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/PhyUtils.o: base/phyLayer/PhyUtils.cc \
	base/messages/AirFrame_m.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/phyLayer/Signal.o: base/phyLayer/Signal.cc \
	base/phyLayer/Interpolation.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/utils/Coord.o: base/utils/Coord.cc \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h
$O/base/utils/NetwToMacControlInfo.o: base/utils/NetwToMacControlInfo.cc \
	base/utils/MiXiMDefs.h \
	base/utils/NetwToMacControlInfo.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h
$O/base/utils/SimpleAddress.o: base/utils/SimpleAddress.cc \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h
$O/environment/Thermal.o: environment/Thermal.cc \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	environment/Thermal.h
$O/environment/ThermalChildress.o: environment/ThermalChildress.cc \
	base/modules/BaseModule.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	environment/ThermalChildress.h \
	environment/WindManager.h
$O/environment/ThermalManager.o: environment/ThermalManager.cc \
	base/modules/BaseModule.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	environment/ThermalChildress.h \
	environment/ThermalManager.h \
	environment/WindManager.h
$O/environment/WindManager.o: environment/WindManager.cc \
	base/modules/BaseModule.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	environment/WindManager.h
$O/glider/application/GliderApplLayer.o: glider/application/GliderApplLayer.cc \
	base/modules/BaseApplLayer.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMobility.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/BatteryAccess.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	environment/ThermalChildress.h \
	environment/ThermalManager.h \
	environment/WindManager.h \
	glider/application/GliderApplLayer.h \
	glider/application/GliderNetworkPkt_m.h \
	glider/mobility/GliderMobility.h \
	glider/mobility/Position.h \
	glider/radio/mac/mac_types.h \
	glider/radio/utils/MacToNetwInfo.h \
	glider/radio/utils/NetwToMacInfo.h \
	simulation/SimulationManager.h
$O/glider/application/GliderNetworkPkt_m.o: glider/application/GliderNetworkPkt_m.cc \
	base/utils/MiXiMDefs.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	glider/application/GliderNetworkPkt_m.h
$O/glider/application/PositionMessage.o: glider/application/PositionMessage.cc \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	glider/application/PositionMessage.h \
	glider/mobility/Position.h
$O/glider/application/Transmission.o: glider/application/Transmission.cc \
	glider/application/Transmission.h
$O/glider/mobility/GliderMobility.o: glider/mobility/GliderMobility.cc \
	base/modules/BaseBattery.h \
	base/modules/BaseMobility.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/BatteryAccess.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/miximkerneldefs.h \
	environment/ThermalChildress.h \
	environment/ThermalManager.h \
	environment/WindManager.h \
	glider/mobility/GliderMobility.h \
	glider/mobility/Position.h \
	simulation/SimulationManager.h
$O/glider/mobility/Position.o: glider/mobility/Position.cc \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	glider/mobility/Position.h
$O/glider/radio/mac/GliderMacLayer.o: glider/radio/mac/GliderMacLayer.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/ChannelAccess.h \
	base/connectionManager/NicEntry.h \
	base/messages/AirFrame_m.h \
	base/messages/ChannelSenseRequest_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseLayer.h \
	base/modules/BaseMacLayer.h \
	base/modules/BaseMobility.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/BatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/BasePhyLayer.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyToMacControlInfo.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/PassedMessage.h \
	base/utils/SimpleAddress.h \
	base/utils/miximkerneldefs.h \
	glider/radio/mac/GliderMacLayer.h \
	glider/radio/mac/MacFrame_m.h \
	glider/radio/mac/mac_pib.h \
	glider/radio/mac/mac_types.h \
	glider/radio/utils/MacToNetwInfo.h \
	glider/radio/utils/NetwToMacInfo.h
$O/glider/radio/mac/MacFrame_m.o: glider/radio/mac/MacFrame_m.cc \
	glider/radio/mac/MacFrame_m.h \
	glider/radio/mac/mac_types.h
$O/glider/radio/phy/GliderAnalogueModel.o: glider/radio/phy/GliderAnalogueModel.cc \
	base/connectionManager/ChannelAccess.h \
	base/messages/AirFrame_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseMobility.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/BatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BasePhyLayer.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/miximkerneldefs.h \
	environment/ThermalChildress.h \
	environment/ThermalManager.h \
	environment/WindManager.h \
	glider/mobility/GliderMobility.h \
	glider/mobility/Position.h \
	glider/radio/phy/GliderAnalogueModel.h \
	glider/radio/phy/GliderPhyLayer.h \
	simulation/SimulationManager.h
$O/glider/radio/phy/GliderDecider.o: glider/radio/phy/GliderDecider.cc \
	base/connectionManager/ChannelAccess.h \
	base/messages/AirFrame_m.h \
	base/messages/ChannelSenseRequest_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseMobility.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/BatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/BasePhyLayer.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/miximkerneldefs.h \
	glider/radio/phy/GliderDecider.h \
	glider/radio/phy/GliderPhyLayer.h
$O/glider/radio/phy/GliderPhyLayer.o: glider/radio/phy/GliderPhyLayer.cc \
	base/connectionManager/BaseConnectionManager.h \
	base/connectionManager/ChannelAccess.h \
	base/connectionManager/NicEntry.h \
	base/messages/AirFrame_m.h \
	base/messages/ChannelSenseRequest_m.h \
	base/modules/BaseBattery.h \
	base/modules/BaseMobility.h \
	base/modules/BaseModule.h \
	base/modules/BaseWorldUtility.h \
	base/modules/BatteryAccess.h \
	base/phyLayer/AnalogueModel.h \
	base/phyLayer/BaseDecider.h \
	base/phyLayer/BasePhyLayer.h \
	base/phyLayer/ChannelInfo.h \
	base/phyLayer/ChannelState.h \
	base/phyLayer/Decider.h \
	base/phyLayer/DeciderToPhyInterface.h \
	base/phyLayer/Interpolation.h \
	base/phyLayer/MacToPhyInterface.h \
	base/phyLayer/Mapping.h \
	base/phyLayer/MappingBase.h \
	base/phyLayer/MappingUtils.h \
	base/phyLayer/PhyUtils.h \
	base/phyLayer/Signal_.h \
	base/utils/Coord.h \
	base/utils/FWMath.h \
	base/utils/FindModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/Move.h \
	base/utils/miximkerneldefs.h \
	glider/radio/phy/GliderAnalogueModel.h \
	glider/radio/phy/GliderDecider.h \
	glider/radio/phy/GliderPhyLayer.h
$O/simulation/SimulationManager.o: simulation/SimulationManager.cc \
	base/modules/BaseModule.h \
	base/utils/HostState.h \
	base/utils/MiXiMDefs.h \
	base/utils/miximkerneldefs.h \
	simulation/SimulationManager.h

