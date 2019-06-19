// -*- C++ -*-
/*!
 * @file  Bridge.cpp * @brief Bridge component * $Date$ 
 *
 * $Id$ 
 */
#include "Bridge.h"

#define TIMESTEP 0.002

// Module specification
// <rtc-template block="module_spec">
static const char* bridge_spec[] =
  {
    "implementation_id", "Bridge",
    "type_name",         "Bridge",
    "description",       "Bridge component",
    "version",           "0.1",
    "vendor",            "AIST",
    "category",          "Generic",
    "activity_type",     "SPORADIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    ""
  };
// </rtc-template>

Bridge::Bridge(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_torqueIn("torqueIn", m_torque),
    m_torqueOut("torqueOut", m_torque)

    // </rtc-template>
{
}

Bridge::~Bridge()
{
}


RTC::ReturnCode_t Bridge::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("torqueIn", m_torqueIn);

  // Set OutPort buffer
  addOutPort("torqueOut", m_torqueOut);

  // Set service provider to Ports

  // Set service consumers to Ports

  // Set CORBA Service Ports

  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable

  // </rtc-template>
  return RTC::RTC_OK;
}


/*
RTC::ReturnCode_t Bridge::onFinalize()
{
  return RTC::RTC_OK;
}
*/
/*
RTC::ReturnCode_t Bridge::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/
/*
RTC::ReturnCode_t Bridge::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

RTC::ReturnCode_t Bridge::onActivated(RTC::UniqueId ec_id)
{
  std::cout << "on Activated" << std::endl;

  return RTC::RTC_OK;
}

RTC::ReturnCode_t Bridge::onDeactivated(RTC::UniqueId ec_id)
{
  std::cout << "on Deactivated" << std::endl;

  return RTC::RTC_OK;
}

RTC::ReturnCode_t Bridge::onExecute(RTC::UniqueId ec_id)
{
  if (m_torqueIn.isNew()) {
    m_torqueIn.read();
    for (int i = 0; i < 53; ++i) {
	std::cout << m_torque.data[i] << " ";
    }
    std::cout << std::endl;
    m_torqueOut.write();
  }

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t Bridge::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/
/*
RTC::ReturnCode_t Bridge::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/
/*
RTC::ReturnCode_t Bridge::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/
/*
RTC::ReturnCode_t Bridge::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/
/*
RTC::ReturnCode_t Bridge::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


extern "C"
{
 
  void BridgeInit(RTC::Manager* manager)
  {
    coil::Properties profile(bridge_spec);
    manager->registerFactory(profile,
                             RTC::Create<Bridge>,
                             RTC::Delete<Bridge>);
  }
  
};



