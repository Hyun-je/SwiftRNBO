//
//  RNBOEventHandler.hpp
//  SwiftRNBO_Example_multiplatfrom_SwiftUI
//
//  Created by Jaehyeon Park on 2023/09/23.
//

#include "RNBO.h"
#import <Foundation/Foundation.h>


class MessageHandler : RNBO::EventHandler {
    
typedef id(*ParameterEventHandler)(id, SEL, const RNBO::ParameterEvent& event);
typedef id(*MessageEventHandler)(id, SEL, const RNBO::MessageEvent& event);
    
public:
    std::function<RNBO::MessageTagInfo(RNBO::MessageTag)> tagResolver;

    id unit;
    SEL parameterEventHandlerSelector;
    SEL messageEventHandlerSelector;
    
    MessageHandler(std::unique_ptr<RNBO::CoreObject> &rnboObject);

private:

    void eventsAvailable() override;
    
    void handleParameterEvent(const RNBO::ParameterEvent& event) override;
    
    void handleMessageEvent(const RNBO::MessageEvent& event) override;
    
};
