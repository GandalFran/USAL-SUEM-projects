/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : IntI2cLdd1.h
**     Project     : AlarmReceiver
**     Processor   : MKE06Z128VLK4
**     Component   : I2C_LDD
**     Version     : Component 01.016, Driver 01.07, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : GNU C Compiler
**     Date/Time   : 2021-06-09, 17:56, # CodeGen: 4
**     Abstract    :
**          This component encapsulates the internal I2C communication
**          interface. The implementation of the interface is based
**          on the Philips I2C-bus specification version 2.0.
**          Interface features:
**          MASTER mode
**            - Multi master communication
**            - The combined format of communication possible
**              (see SendStop parameter in MasterSend/ReceiveBlock method)
**            - 7-bit slave addressing (10-bit addressing can be made as well)
**            - Acknowledge polling provided
**            - No wait state initiated when a slave device holds the SCL line low
**            - Holding of the SCL line low by slave device recognized as 'not available bus'
**            - Invalid start/stop condition detection provided
**          SLAVE mode
**            - 7-bit slave addressing
**            - General call address detection provided
**     Settings    :
**          Component name                                 : IntI2cLdd1
**          I2C channel                                    : I2C1
**          Interrupt service                              : Enabled
**            Interrupt                                    : INT_I2C1
**            Interrupt priority                           : medium priority
**            ISR name                                     : IntI2cLdd1_Interrupt
**          Settings                                       : 
**            Mode selection                               : MASTER
**            MASTER mode                                  : Enabled
**              Initialization                             : 
**                Address mode                             : 7-bit addressing
**                Target slave address init                : 8
**            SLAVE mode                                   : Disabled
**            Pins                                         : 
**              SDA pin                                    : 
**                SDA pin                                  : PTE0/KBI1_P0/SPI0_SCK/TCLK1/I2C1_SDA
**              SCL pin                                    : 
**                SCL pin                                  : PTE1/KBI1_P1/SPI0_MOSI/I2C1_SCL
**              Input Glitch filter                        : 0
**            Internal frequency (multiplier factor)       : 12 MHz
**            Bits 0-2 of Frequency divider register       : 000
**            Bits 3-5 of Frequency divider register       : 000
**            SCL frequency                                : 600 kHz
**            SDA Hold                                     : 0.583 us
**            SCL start Hold                               : 0.5 us
**            SCL stop Hold                                : 0.917 us
**            Control acknowledge bit                      : Disabled
**            Low timeout                                  : Disabled
**          Initialization                                 : 
**            Enabled in init code                         : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnMasterBlockSent                          : Enabled
**              OnMasterBlockReceived                      : Enabled
**              OnMasterByteReceived                       : Disabled
**              OnSlaveBlockSent                           : Disabled
**              OnSlaveBlockReceived                       : Disabled
**              OnSlaveByteReceived                        : Disabled
**              OnSlaveRxRequest                           : Disabled
**              OnSlaveTxRequest                           : Disabled
**              OnSlaveGeneralCallAddr                     : Disabled
**              OnSlaveSmBusCallAddr                       : Disabled
**              OnSlaveSmBusAlertResponse                  : Disabled
**              OnError                                    : Disabled
**              OnBusStartDetected                         : Disabled
**              OnBusStopDetected                          : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init                     - LDD_TDeviceData* IntI2cLdd1_Init(LDD_TUserData *UserDataPtr);
**         MasterSendBlock          - LDD_TError IntI2cLdd1_MasterSendBlock(LDD_TDeviceData *DeviceDataPtr,...
**         MasterGetSentDataNum     - LDD_I2C_TSize IntI2cLdd1_MasterGetSentDataNum(LDD_TDeviceData *DeviceDataPtr);
**         MasterReceiveBlock       - LDD_TError IntI2cLdd1_MasterReceiveBlock(LDD_TDeviceData *DeviceDataPtr,...
**         MasterGetReceivedDataNum - LDD_I2C_TSize IntI2cLdd1_MasterGetReceivedDataNum(LDD_TDeviceData...
**         SelectSlaveDevice        - LDD_TError IntI2cLdd1_SelectSlaveDevice(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file IntI2cLdd1.h
** @version 01.07
** @brief
**          This component encapsulates the internal I2C communication
**          interface. The implementation of the interface is based
**          on the Philips I2C-bus specification version 2.0.
**          Interface features:
**          MASTER mode
**            - Multi master communication
**            - The combined format of communication possible
**              (see SendStop parameter in MasterSend/ReceiveBlock method)
**            - 7-bit slave addressing (10-bit addressing can be made as well)
**            - Acknowledge polling provided
**            - No wait state initiated when a slave device holds the SCL line low
**            - Holding of the SCL line low by slave device recognized as 'not available bus'
**            - Invalid start/stop condition detection provided
**          SLAVE mode
**            - 7-bit slave addressing
**            - General call address detection provided
*/         
/*!
**  @addtogroup IntI2cLdd1_module IntI2cLdd1 module documentation
**  @{
*/         

#ifndef __IntI2cLdd1_H
#define __IntI2cLdd1_H

/* MODULE IntI2cLdd1. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited components */

#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*! Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define IntI2cLdd1_PRPH_BASE_ADDRESS  0x40067000U
  
/* Methods configuration constants - generated for all enabled component's methods */
#define IntI2cLdd1_Init_METHOD_ENABLED /*!< Init method of the component IntI2cLdd1 is enabled (generated) */
#define IntI2cLdd1_MasterSendBlock_METHOD_ENABLED /*!< MasterSendBlock method of the component IntI2cLdd1 is enabled (generated) */
#define IntI2cLdd1_MasterGetSentDataNum_METHOD_ENABLED /*!< MasterGetSentDataNum method of the component IntI2cLdd1 is enabled (generated) */
#define IntI2cLdd1_MasterReceiveBlock_METHOD_ENABLED /*!< MasterReceiveBlock method of the component IntI2cLdd1 is enabled (generated) */
#define IntI2cLdd1_MasterGetReceivedDataNum_METHOD_ENABLED /*!< MasterGetReceivedDataNum method of the component IntI2cLdd1 is enabled (generated) */
#define IntI2cLdd1_SelectSlaveDevice_METHOD_ENABLED /*!< SelectSlaveDevice method of the component IntI2cLdd1 is enabled (generated) */

/* Events configuration constants - generated for all enabled component's events */
#define IntI2cLdd1_OnMasterBlockSent_EVENT_ENABLED /*!< OnMasterBlockSent event of the component IntI2cLdd1 is enabled (generated) */
#define IntI2cLdd1_OnMasterBlockReceived_EVENT_ENABLED /*!< OnMasterBlockReceived event of the component IntI2cLdd1 is enabled (generated) */



/*
** ===================================================================
**     Method      :  IntI2cLdd1_Init (component I2C_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the device data structure. 
*/
/* ===================================================================*/
LDD_TDeviceData* IntI2cLdd1_Init(LDD_TUserData *UserDataPtr);

/*
** ===================================================================
**     Method      :  IntI2cLdd1_MasterSendBlock (component I2C_LDD)
*/
/*!
**     @brief
**         This method writes one (7-bit addressing) or two (10-bit
**         addressing) slave address bytes inclusive of R/W bit = 0 to
**         the I2C bus and then writes the block of characters to the
**         bus. The slave address must be specified before, by the
**         "SelectSlaveDevice" method or in component initialization
**         section, "Target slave address init" property. If the method
**         returns ERR_OK, it doesn't mean that transmission was
**         successful. The state of transmission is detectable by means
**         of events (OnMasterSendComplete or OnError). Data to be sent
**         are not copied to an internal buffer and remains in the
**         original location. Therefore the content of the buffer
**         should not be changed until the transmission is complete.
**         Event "OnMasterBlockSent"can be used to detect the end of
**         the transmission. This method is available only for the
**         MASTER or MASTER - SLAVE mode.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to the block of data
**                           to send.
**     @param
**         Size            - Size of the data block.
**     @param
**         SendStop        - Parameter for generating I2C
**                           Stop condition
**                           LDD_I2C_SEND_STOP - Stop condition is
**                           generated on end transmission.
**                           LDD_I2C_NO_SEND_STOP - Stop condition isn't
**                           generated on end transmission.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The I2C device is now running
*/
/* ===================================================================*/
LDD_TError IntI2cLdd1_MasterSendBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size, LDD_I2C_TSendStop SendStop);

/*
** ===================================================================
**     Method      :  IntI2cLdd1_MasterGetSentDataNum (component I2C_LDD)
*/
/*!
**     @brief
**         This method returns the number of transmitted characters
**         from the transmit buffer. This method is available only for
**         the MASTER mode and if method MasterSendBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - The number of sent characters.
*/
/* ===================================================================*/
LDD_I2C_TSize IntI2cLdd1_MasterGetSentDataNum(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  IntI2cLdd1_MasterReceiveBlock (component I2C_LDD)
*/
/*!
**     @brief
**         This method writes one (7-bit addressing) or two (10-bit
**         addressing) slave address bytes inclusive of R/W bit = 1 to
**         the I2C bus and then receives the block of characters from
**         the bus. The slave address must be specified before, by the
**         "SelectSlaveDevice" method or in component initialization
**         section, "Target slave address init" property. If the method
**         returns ERR_OK, it doesn't mean that reception was
**         successful. The state of reception is detectable by means of
**         events (OnMasterSendComplete  or OnError). Data to be
**         received are not copied to an internal buffer and remains in
**         the original location. Therefore the content of the buffer
**         should not be changed until the transmission is complete.
**         Event "OnMasterBlockReceived"can be used to detect the end
**         of the reception. This method is available only for the
**         MASTER or MASTER - SLAVE mode.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         BufferPtr       - Pointer to a buffer where
**                           received characters will be stored.
**     @param
**         Size            - The size of the block.
**     @param
**         SendStop        - Parameter for generating I2C
**                           Stop condition
**                           LDD_I2C_SEND_STOP - Stop condition is
**                           generated on end transmission.
**                           LDD_I2C_NO_SEND_STOP - Stop condition isn't
**                           generated on end transmission.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_DISABLED -  Device is disabled
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_BUSY - The master device is busy
**                           ERR_NOTAVAIL - It is not possible to
**                           receive data if general call address is set.
**                           ERR_PARAM_MODE -  Stop condition isn't
**                           possible generated on end transmission.
*/
/* ===================================================================*/
LDD_TError IntI2cLdd1_MasterReceiveBlock(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr, LDD_I2C_TSize Size, LDD_I2C_TSendStop SendStop);

/*
** ===================================================================
**     Method      :  IntI2cLdd1_MasterGetReceivedDataNum (component I2C_LDD)
*/
/*!
**     @brief
**         This method returns the number of received characters in the
**         receive buffer. This method is available only for the MASTER
**         mode and if method MasterReceiveBlock is enabled.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - The number of characters in the input
**                           buffer.
*/
/* ===================================================================*/
LDD_I2C_TSize IntI2cLdd1_MasterGetReceivedDataNum(LDD_TDeviceData *DeviceDataPtr);

/*
** ===================================================================
**     Method      :  IntI2cLdd1_SelectSlaveDevice (component I2C_LDD)
*/
/*!
**     @brief
**         This method selects a new slave for communication by its
**         7-bit slave, 10-bit address or general call value. Any send
**         or receive method directs to or from selected device, until
**         a new slave device is selected by this method. This method
**         is available for the MASTER mode.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         AddrType        - Specify type of slave address
**                           (7bit, 10bit or general call address), e.g.
**                           LDD_I2C_ADDRTYPE_7BITS.
**     @param
**         Addr            - 7bit or 10bit slave address value.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_BUSY - The device is busy, wait until
**                           the current operation is finished.
**                           ERR_DISABLED -  The device is disabled.
**                           ERR_SPEED - This device does not work in
**                           the active clock configuration
**                           ERR_PARAM_ADDRESS_TYPE -  Invalid address
**                           type.
**                           ERR_PARAM_ADDRESS -  Invalid address value.
*/
/* ===================================================================*/
LDD_TError IntI2cLdd1_SelectSlaveDevice(LDD_TDeviceData *DeviceDataPtr, LDD_I2C_TAddrType AddrType, LDD_I2C_TAddr Addr);

/*
** ===================================================================
**     Method      :  IntI2cLdd1_Interrupt (component I2C_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/* {Default RTOS Adapter} ISR function prototype */
PE_ISR(IntI2cLdd1_Interrupt);

/* END IntI2cLdd1. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif
/* ifndef __IntI2cLdd1_H */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
