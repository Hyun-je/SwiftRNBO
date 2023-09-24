//
//  RNBOEventHandler.cpp
//  SwiftRNBO_Example_multiplatfrom_SwiftUI
//
//  Created by Jaehyeon Park on 2023/09/23.
//

#include "RNBOEventHandler.hpp"
#include <iostream>

using namespace RNBO;


MessageHandler::MessageHandler(std::unique_ptr<RNBO::CoreObject> &rnboObject) {
    tagResolver = [&rnboObject](RNBO::MessageTag tag) { return rnboObject->resolveTag(tag); };
}


void MessageHandler::eventsAvailable() {
    drainEvents();
}

void MessageHandler::handleParameterEvent(const RNBO::ParameterEvent& event) {

    ParameterEventHandler handler = (ParameterEventHandler)[unit methodForSelector:parameterEventHandlerSelector];
    handler(unit, parameterEventHandlerSelector, event);
    
}

void MessageHandler::handleMessageEvent(const MessageEvent& event) {
    
    MessageEventHandler handler = (MessageEventHandler)[unit methodForSelector:messageEventHandlerSelector];
    handler(unit, messageEventHandlerSelector, event);
    
}

