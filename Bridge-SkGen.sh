#!/bin/sh

rtc-template -bcxx \
--module-name=Bridge --module-desc="Bridge component" \
--module-version=0.1 --module-vendor=AIST --module-category=Generic \
--module-comp-type=DataFlowComponent --module-act-type=SPORADIC \
--module-max-inst=1  \
--inport=torqueIn:TimedDoubleSeq \
--outport=torqueOut:TimedDoubleSeq
