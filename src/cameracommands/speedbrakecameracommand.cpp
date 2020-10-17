#include "cameracommands/speedbrakecameracommand.h"
#include <CHeaders/XPLM/XPLMDataAccess.h>
#include <CHeaders/XPLM/XPLMUtilities.h>
#include <algorithm>
#include "cameraposition.h"
#include "helpers.h"
#include "interfaces/ivisitor.h"

// default constructor
SpeedBrakeCameraCommand::SpeedBrakeCameraCommand() {
    mGNormalDataRef = XPLMFindDataRef("sim/flightmodel/forces/g_nrml");
    mGSideDataRef = XPLMFindDataRef("sim/flightmodel/forces/g_side");
    mGAxilDataRef = XPLMFindDataRef("sim/flightmodel/forces/g_axil");
    mBrakeDeployment = XPLMFindDataRef("sim/flightmodel/controls/sbrkat");
    mResponse = 25;
    mLastPitch = 0;
    mLastRoll = 0;
    mLastX = 0;
    mLastNormG = 1;
}

// default destructor
SpeedBrakeCameraCommand::~SpeedBrakeCameraCommand() {}

void SpeedBrakeCameraCommand::execute(CameraPosition& position,
                                      float elapsedTime) {
    CameraCommand::execute(position, elapsedTime);
    float acc, currentNormalG, currentSideG, currentBrakeDeployment;

    // Restore the initial position
    position.pitch -= mLastPitch;
    position.roll -= mLastRoll;
    position.x -= mLastX;

    // Reset the state vars
    mLastPitch = 0;
    mLastRoll = 0;
    mLastX = 0;

    // Exit if disabled
    if (!pEnabled)
        return;
}