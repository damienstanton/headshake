#ifndef SPEEDBRAKECAMERACOMMAND_H
#define SPEEDBRAKECAMERACOMMAND_H

#include <CHeaders/XPLM/XPLMDataAccess.h>
#include <vector>
#include "cameracommands/cameracommand.h"
#include "cameraposition.h"

class SpeedBrakeCameraCommand : public CameraCommand {
   public:
    SpeedBrakeCameraCommand();
    virtual ~SpeedBrakeCameraCommand();
    void execute(CameraPosition&, float) override;
    void accept(IVisitor&);

    void set_response(float);
    float get_response();

   private:
    std::vector<float> mPitchFilter;
    std::vector<float> mYawFilter;
    float mLastPitch;
    float mResponse;
    float mLastX;
    float mLastRoll;
    float mLastNormG;
    XPLMDataRef mGNormalDataRef;
    XPLMDataRef mGSideDataRef;
    XPLMDataRef mGAxilDataRef;
    XPLMDataRef mBrakeDeployment;
};

#endif  // SPEEDBRAKECAMERACOMMAND_H