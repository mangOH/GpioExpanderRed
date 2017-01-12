/**
 * @file
 *
 * Prototype GPIO Expander API interface.
 * The GPIO API implementation of GPIO Expander on MangOH Red board
 *
 * <HR>
 *
 * Copyright (C) Sierra Wireless Inc. Use of this work is subject to license.
 */

#include "legato.h"
#include "interfaces.h"
#include "gpioExpander.h"
// Only required for control of i2c switch, which shouldn't be in this file to begin with.
// On yocto the file has a different non-standard name.
#ifdef LEGATO_EMBEDDED
#include <linux/i2c-dev-user.h>
#else
#include <linux/i2c-dev.h>
#endif

//--------------------------------------------------------------------------------------------------
/**
 * I2C slave address of the I2C switch.
 *
 * @todo this device should not be controlled by this module.
 */
//--------------------------------------------------------------------------------------------------
#define I2C_SWITCH_PCA9548A_ADDR            0x71

//--------------------------------------------------------------------------------------------------
/**
 * I2C slave address of the GPIO expander on the MangOH Red board
 */
//--------------------------------------------------------------------------------------------------
#define I2C_SX1509_GPIO_EXPANDER_ADDR      0x3E

//--------------------------------------------------------------------------------------------------
/**
 * Pin spec arrays.
 */
//--------------------------------------------------------------------------------------------------

static const gpioExpander_PinSpec_t expanderPinSpecs[16] =
{
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 0 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 1 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 2 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 3 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 4 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 5 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 6 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 7 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 8 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 9 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 10 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 11 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 12 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 13 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 14 },
    { .i2cBus = 0, .i2cAddr = I2C_SX1509_GPIO_EXPANDER_ADDR, .pin = 15 },
};

// Note: will be zeroed by spec, so no need to explicitly initialize the values
static gpioExpander_HandlerRecord_t handlerRecords[16];

//--------------------------------------------------------------------------------------------------
// BEGIN GENERATED CODE
//
// Consider regenerating this code if modifications are required.  This code generation is done at
// design time and checked in.
//--------------------------------------------------------------------------------------------------

// GPIO expander #1 GPIO 0
le_result_t mangoh_gpioExp1Pin0_SetInput
(
    mangoh_gpioExp1Pin0_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[0], polarity);
}

le_result_t mangoh_gpioExp1Pin0_SetPushPullOutput
(
    mangoh_gpioExp1Pin0_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[0], polarity, value);
}

le_result_t mangoh_gpioExp1Pin0_SetTriStateOutput
(
    mangoh_gpioExp1Pin0_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[0], polarity);
}

le_result_t mangoh_gpioExp1Pin0_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin0_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[0], polarity, value);
}

le_result_t mangoh_gpioExp1Pin0_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[0]);
}

le_result_t mangoh_gpioExp1Pin0_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[0]);
}

le_result_t mangoh_gpioExp1Pin0_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[0]);
}

le_result_t mangoh_gpioExp1Pin0_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[0]);
}

le_result_t mangoh_gpioExp1Pin0_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[0]);
}

le_result_t mangoh_gpioExp1Pin0_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[0]);
}

bool mangoh_gpioExp1Pin0_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[0]);
}

le_result_t mangoh_gpioExp1Pin0_SetEdgeSense
(
    mangoh_gpioExp1Pin0_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[0], trigger);
}

mangoh_gpioExp1Pin0_Edge_t mangoh_gpioExp1Pin0_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[0]);
}

le_result_t mangoh_gpioExp1Pin0_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[0]);
}

bool mangoh_gpioExp1Pin0_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[0]);
}

bool mangoh_gpioExp1Pin0_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[0]);
}

mangoh_gpioExp1Pin0_Polarity_t mangoh_gpioExp1Pin0_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[0]);
}

bool mangoh_gpioExp1Pin0_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[0]);
}

mangoh_gpioExp1Pin0_PullUpDown_t mangoh_gpioExp1Pin0_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[0]);
}

mangoh_gpioExp1Pin0_ChangeEventHandlerRef_t mangoh_gpioExp1Pin0_AddChangeEventHandler
(
    mangoh_gpioExp1Pin0_Edge_t trigger,
    mangoh_gpioExp1Pin0_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin0_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[0],
        &handlerRecords[0],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin0_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin0_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[0],
        &handlerRecords[0],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 1
le_result_t mangoh_gpioExp1Pin1_SetInput
(
    mangoh_gpioExp1Pin1_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[1], polarity);
}

le_result_t mangoh_gpioExp1Pin1_SetPushPullOutput
(
    mangoh_gpioExp1Pin1_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[1], polarity, value);
}

le_result_t mangoh_gpioExp1Pin1_SetTriStateOutput
(
    mangoh_gpioExp1Pin1_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[1], polarity);
}

le_result_t mangoh_gpioExp1Pin1_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin1_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[1], polarity, value);
}

le_result_t mangoh_gpioExp1Pin1_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[1]);
}

le_result_t mangoh_gpioExp1Pin1_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[1]);
}

le_result_t mangoh_gpioExp1Pin1_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[1]);
}

le_result_t mangoh_gpioExp1Pin1_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[1]);
}

le_result_t mangoh_gpioExp1Pin1_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[1]);
}

le_result_t mangoh_gpioExp1Pin1_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[1]);
}

bool mangoh_gpioExp1Pin1_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[1]);
}

le_result_t mangoh_gpioExp1Pin1_SetEdgeSense
(
    mangoh_gpioExp1Pin1_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[1], trigger);
}

mangoh_gpioExp1Pin1_Edge_t mangoh_gpioExp1Pin1_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[1]);
}

le_result_t mangoh_gpioExp1Pin1_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[1]);
}

bool mangoh_gpioExp1Pin1_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[1]);
}

bool mangoh_gpioExp1Pin1_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[1]);
}

mangoh_gpioExp1Pin1_Polarity_t mangoh_gpioExp1Pin1_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[1]);
}

bool mangoh_gpioExp1Pin1_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[1]);
}

mangoh_gpioExp1Pin1_PullUpDown_t mangoh_gpioExp1Pin1_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[1]);
}

mangoh_gpioExp1Pin1_ChangeEventHandlerRef_t mangoh_gpioExp1Pin1_AddChangeEventHandler
(
    mangoh_gpioExp1Pin1_Edge_t trigger,
    mangoh_gpioExp1Pin1_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin1_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[1],
        &handlerRecords[1],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin1_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin1_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[1],
        &handlerRecords[1],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 2
le_result_t mangoh_gpioExp1Pin2_SetInput
(
    mangoh_gpioExp1Pin2_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[2], polarity);
}

le_result_t mangoh_gpioExp1Pin2_SetPushPullOutput
(
    mangoh_gpioExp1Pin2_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[2], polarity, value);
}

le_result_t mangoh_gpioExp1Pin2_SetTriStateOutput
(
    mangoh_gpioExp1Pin2_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[2], polarity);
}

le_result_t mangoh_gpioExp1Pin2_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin2_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[2], polarity, value);
}

le_result_t mangoh_gpioExp1Pin2_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[2]);
}

le_result_t mangoh_gpioExp1Pin2_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[2]);
}

le_result_t mangoh_gpioExp1Pin2_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[2]);
}

le_result_t mangoh_gpioExp1Pin2_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[2]);
}

le_result_t mangoh_gpioExp1Pin2_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[2]);
}

le_result_t mangoh_gpioExp1Pin2_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[2]);
}

bool mangoh_gpioExp1Pin2_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[2]);
}

le_result_t mangoh_gpioExp1Pin2_SetEdgeSense
(
    mangoh_gpioExp1Pin2_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[2], trigger);
}

mangoh_gpioExp1Pin2_Edge_t mangoh_gpioExp1Pin2_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[2]);
}

le_result_t mangoh_gpioExp1Pin2_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[2]);
}

bool mangoh_gpioExp1Pin2_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[2]);
}

bool mangoh_gpioExp1Pin2_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[2]);
}

mangoh_gpioExp1Pin2_Polarity_t mangoh_gpioExp1Pin2_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[2]);
}

bool mangoh_gpioExp1Pin2_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[2]);
}

mangoh_gpioExp1Pin2_PullUpDown_t mangoh_gpioExp1Pin2_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[2]);
}

mangoh_gpioExp1Pin2_ChangeEventHandlerRef_t mangoh_gpioExp1Pin2_AddChangeEventHandler
(
    mangoh_gpioExp1Pin2_Edge_t trigger,
    mangoh_gpioExp1Pin2_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin2_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[2],
        &handlerRecords[2],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin2_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin2_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[2],
        &handlerRecords[2],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 3
le_result_t mangoh_gpioExp1Pin3_SetInput
(
    mangoh_gpioExp1Pin3_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[3], polarity);
}

le_result_t mangoh_gpioExp1Pin3_SetPushPullOutput
(
    mangoh_gpioExp1Pin3_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[3], polarity, value);
}

le_result_t mangoh_gpioExp1Pin3_SetTriStateOutput
(
    mangoh_gpioExp1Pin3_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[3], polarity);
}

le_result_t mangoh_gpioExp1Pin3_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin3_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(
        &expanderPinSpecs[3], polarity, value);
}

le_result_t mangoh_gpioExp1Pin3_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[3]);
}

le_result_t mangoh_gpioExp1Pin3_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[3]);
}

le_result_t mangoh_gpioExp1Pin3_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[3]);
}

le_result_t mangoh_gpioExp1Pin3_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[3]);
}

le_result_t mangoh_gpioExp1Pin3_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[3]);
}

le_result_t mangoh_gpioExp1Pin3_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[3]);
}

bool mangoh_gpioExp1Pin3_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[3]);
}

le_result_t mangoh_gpioExp1Pin3_SetEdgeSense
(
    mangoh_gpioExp1Pin3_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[3], trigger);
}

mangoh_gpioExp1Pin3_Edge_t mangoh_gpioExp1Pin3_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[3]);
}

le_result_t mangoh_gpioExp1Pin3_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[3]);
}

bool mangoh_gpioExp1Pin3_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[3]);
}

bool mangoh_gpioExp1Pin3_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[3]);
}

mangoh_gpioExp1Pin3_Polarity_t mangoh_gpioExp1Pin3_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[3]);
}

bool mangoh_gpioExp1Pin3_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[3]);
}

mangoh_gpioExp1Pin3_PullUpDown_t mangoh_gpioExp1Pin3_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[3]);
}

mangoh_gpioExp1Pin3_ChangeEventHandlerRef_t mangoh_gpioExp1Pin3_AddChangeEventHandler
(
    mangoh_gpioExp1Pin3_Edge_t trigger,
    mangoh_gpioExp1Pin3_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin3_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[3],
        &handlerRecords[3],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin3_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin3_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[3],
        &handlerRecords[3],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 4
le_result_t mangoh_gpioExp1Pin4_SetInput
(
    mangoh_gpioExp1Pin4_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[4], polarity);
}

le_result_t mangoh_gpioExp1Pin4_SetPushPullOutput
(
    mangoh_gpioExp1Pin4_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[4], polarity, value);
}

le_result_t mangoh_gpioExp1Pin4_SetTriStateOutput
(
    mangoh_gpioExp1Pin4_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[4], polarity);
}

le_result_t mangoh_gpioExp1Pin4_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin4_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[4], polarity, value);
}

le_result_t mangoh_gpioExp1Pin4_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[4]);
}

le_result_t mangoh_gpioExp1Pin4_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[4]);
}

le_result_t mangoh_gpioExp1Pin4_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[4]);
}

le_result_t mangoh_gpioExp1Pin4_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[4]);
}

le_result_t mangoh_gpioExp1Pin4_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[4]);
}

le_result_t mangoh_gpioExp1Pin4_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[4]);
}

bool mangoh_gpioExp1Pin4_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[4]);
}

le_result_t mangoh_gpioExp1Pin4_SetEdgeSense
(
    mangoh_gpioExp1Pin4_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[4], trigger);
}

mangoh_gpioExp1Pin4_Edge_t mangoh_gpioExp1Pin4_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[4]);
}

le_result_t mangoh_gpioExp1Pin4_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[4]);
}

bool mangoh_gpioExp1Pin4_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[4]);
}

bool mangoh_gpioExp1Pin4_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[4]);
}

mangoh_gpioExp1Pin4_Polarity_t mangoh_gpioExp1Pin4_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[4]);
}

bool mangoh_gpioExp1Pin4_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[4]);
}

mangoh_gpioExp1Pin4_PullUpDown_t mangoh_gpioExp1Pin4_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[4]);
}

mangoh_gpioExp1Pin4_ChangeEventHandlerRef_t mangoh_gpioExp1Pin4_AddChangeEventHandler
(
    mangoh_gpioExp1Pin4_Edge_t trigger,
    mangoh_gpioExp1Pin4_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin4_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[4],
        &handlerRecords[4],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin4_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin4_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[4],
        &handlerRecords[4],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 5
le_result_t mangoh_gpioExp1Pin5_SetInput
(
    mangoh_gpioExp1Pin5_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[5], polarity);
}

le_result_t mangoh_gpioExp1Pin5_SetPushPullOutput
(
    mangoh_gpioExp1Pin5_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[5], polarity, value);
}

le_result_t mangoh_gpioExp1Pin5_SetTriStateOutput
(
    mangoh_gpioExp1Pin5_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[5], polarity);
}

le_result_t mangoh_gpioExp1Pin5_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin5_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[5], polarity, value);
}

le_result_t mangoh_gpioExp1Pin5_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[5]);
}

le_result_t mangoh_gpioExp1Pin5_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[5]);
}

le_result_t mangoh_gpioExp1Pin5_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[5]);
}

le_result_t mangoh_gpioExp1Pin5_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[5]);
}

le_result_t mangoh_gpioExp1Pin5_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[5]);
}

le_result_t mangoh_gpioExp1Pin5_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[5]);
}

bool mangoh_gpioExp1Pin5_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[5]);
}

le_result_t mangoh_gpioExp1Pin5_SetEdgeSense
(
    mangoh_gpioExp1Pin5_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[5], trigger);
}

mangoh_gpioExp1Pin5_Edge_t mangoh_gpioExp1Pin5_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[5]);
}

le_result_t mangoh_gpioExp1Pin5_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[5]);
}

bool mangoh_gpioExp1Pin5_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[5]);
}

bool mangoh_gpioExp1Pin5_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[5]);
}

mangoh_gpioExp1Pin5_Polarity_t mangoh_gpioExp1Pin5_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[5]);
}

bool mangoh_gpioExp1Pin5_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[5]);
}

mangoh_gpioExp1Pin5_PullUpDown_t mangoh_gpioExp1Pin5_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[5]);
}

mangoh_gpioExp1Pin5_ChangeEventHandlerRef_t mangoh_gpioExp1Pin5_AddChangeEventHandler
(
    mangoh_gpioExp1Pin5_Edge_t trigger,
    mangoh_gpioExp1Pin5_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin5_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[5],
        &handlerRecords[5],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin5_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin5_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[5],
        &handlerRecords[5],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 6
le_result_t mangoh_gpioExp1Pin6_SetInput
(
    mangoh_gpioExp1Pin6_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[6], polarity);
}

le_result_t mangoh_gpioExp1Pin6_SetPushPullOutput
(
    mangoh_gpioExp1Pin6_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[6], polarity, value);
}

le_result_t mangoh_gpioExp1Pin6_SetTriStateOutput
(
    mangoh_gpioExp1Pin6_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[6], polarity);
}

le_result_t mangoh_gpioExp1Pin6_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin6_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[6], polarity, value);
}

le_result_t mangoh_gpioExp1Pin6_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[6]);
}

le_result_t mangoh_gpioExp1Pin6_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[6]);
}

le_result_t mangoh_gpioExp1Pin6_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[6]);
}

le_result_t mangoh_gpioExp1Pin6_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[6]);
}

le_result_t mangoh_gpioExp1Pin6_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[6]);
}

le_result_t mangoh_gpioExp1Pin6_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[6]);
}

bool mangoh_gpioExp1Pin6_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[6]);
}

le_result_t mangoh_gpioExp1Pin6_SetEdgeSense
(
    mangoh_gpioExp1Pin6_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[6], trigger);
}

mangoh_gpioExp1Pin6_Edge_t mangoh_gpioExp1Pin6_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[6]);
}

le_result_t mangoh_gpioExp1Pin6_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[6]);
}

bool mangoh_gpioExp1Pin6_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[6]);
}

bool mangoh_gpioExp1Pin6_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[6]);
}

mangoh_gpioExp1Pin6_Polarity_t mangoh_gpioExp1Pin6_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[6]);
}

bool mangoh_gpioExp1Pin6_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[6]);
}

mangoh_gpioExp1Pin6_PullUpDown_t mangoh_gpioExp1Pin6_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[6]);
}

mangoh_gpioExp1Pin6_ChangeEventHandlerRef_t mangoh_gpioExp1Pin6_AddChangeEventHandler
(
    mangoh_gpioExp1Pin6_Edge_t trigger,
    mangoh_gpioExp1Pin6_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin6_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[6],
        &handlerRecords[6],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin6_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin6_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[6],
        &handlerRecords[6],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 7
le_result_t mangoh_gpioExp1Pin7_SetInput
(
    mangoh_gpioExp1Pin7_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[7], polarity);
}

le_result_t mangoh_gpioExp1Pin7_SetPushPullOutput
(
    mangoh_gpioExp1Pin7_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[7], polarity, value);
}

le_result_t mangoh_gpioExp1Pin7_SetTriStateOutput
(
    mangoh_gpioExp1Pin7_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[7], polarity);
}

le_result_t mangoh_gpioExp1Pin7_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin7_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[7], polarity, value);
}

le_result_t mangoh_gpioExp1Pin7_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[7]);
}

le_result_t mangoh_gpioExp1Pin7_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[7]);
}

le_result_t mangoh_gpioExp1Pin7_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[7]);
}

le_result_t mangoh_gpioExp1Pin7_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[7]);
}

le_result_t mangoh_gpioExp1Pin7_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[7]);
}

le_result_t mangoh_gpioExp1Pin7_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[7]);
}

bool mangoh_gpioExp1Pin7_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[7]);
}

le_result_t mangoh_gpioExp1Pin7_SetEdgeSense
(
    mangoh_gpioExp1Pin7_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[7], trigger);
}

mangoh_gpioExp1Pin7_Edge_t mangoh_gpioExp1Pin7_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[7]);
}

le_result_t mangoh_gpioExp1Pin7_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[7]);
}

bool mangoh_gpioExp1Pin7_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[7]);
}

bool mangoh_gpioExp1Pin7_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[7]);
}

mangoh_gpioExp1Pin7_Polarity_t mangoh_gpioExp1Pin7_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[7]);
}

bool mangoh_gpioExp1Pin7_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[7]);
}

mangoh_gpioExp1Pin7_PullUpDown_t mangoh_gpioExp1Pin7_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[7]);
}

mangoh_gpioExp1Pin7_ChangeEventHandlerRef_t mangoh_gpioExp1Pin7_AddChangeEventHandler
(
    mangoh_gpioExp1Pin7_Edge_t trigger,
    mangoh_gpioExp1Pin7_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin7_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[7],
        &handlerRecords[7],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin7_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin7_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[7],
        &handlerRecords[7],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 8
le_result_t mangoh_gpioExp1Pin8_SetInput
(
    mangoh_gpioExp1Pin8_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[8], polarity);
}

le_result_t mangoh_gpioExp1Pin8_SetPushPullOutput
(
    mangoh_gpioExp1Pin8_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[8], polarity, value);
}

le_result_t mangoh_gpioExp1Pin8_SetTriStateOutput
(
    mangoh_gpioExp1Pin8_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[8], polarity);
}

le_result_t mangoh_gpioExp1Pin8_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin8_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[8], polarity, value);
}

le_result_t mangoh_gpioExp1Pin8_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[8]);
}

le_result_t mangoh_gpioExp1Pin8_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[8]);
}

le_result_t mangoh_gpioExp1Pin8_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[8]);
}

le_result_t mangoh_gpioExp1Pin8_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[8]);
}

le_result_t mangoh_gpioExp1Pin8_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[8]);
}

le_result_t mangoh_gpioExp1Pin8_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[8]);
}

bool mangoh_gpioExp1Pin8_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[8]);
}

le_result_t mangoh_gpioExp1Pin8_SetEdgeSense
(
    mangoh_gpioExp1Pin8_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[8], trigger);
}

mangoh_gpioExp1Pin8_Edge_t mangoh_gpioExp1Pin8_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[8]);
}

le_result_t mangoh_gpioExp1Pin8_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[8]);
}

bool mangoh_gpioExp1Pin8_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[8]);
}

bool mangoh_gpioExp1Pin8_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[8]);
}

mangoh_gpioExp1Pin8_Polarity_t mangoh_gpioExp1Pin8_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[8]);
}

bool mangoh_gpioExp1Pin8_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[8]);
}

mangoh_gpioExp1Pin8_PullUpDown_t mangoh_gpioExp1Pin8_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[8]);
}

mangoh_gpioExp1Pin8_ChangeEventHandlerRef_t mangoh_gpioExp1Pin8_AddChangeEventHandler
(
    mangoh_gpioExp1Pin8_Edge_t trigger,
    mangoh_gpioExp1Pin8_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin8_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[8],
        &handlerRecords[8],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin8_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin8_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[8],
        &handlerRecords[8],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 9
le_result_t mangoh_gpioExp1Pin9_SetInput
(
    mangoh_gpioExp1Pin9_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[9], polarity);
}

le_result_t mangoh_gpioExp1Pin9_SetPushPullOutput
(
    mangoh_gpioExp1Pin9_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[9], polarity, value);
}

le_result_t mangoh_gpioExp1Pin9_SetTriStateOutput
(
    mangoh_gpioExp1Pin9_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[9], polarity);
}

le_result_t mangoh_gpioExp1Pin9_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin9_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(
        &expanderPinSpecs[9], polarity, value);
}

le_result_t mangoh_gpioExp1Pin9_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[9]);
}

le_result_t mangoh_gpioExp1Pin9_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[9]);
}

le_result_t mangoh_gpioExp1Pin9_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[9]);
}

le_result_t mangoh_gpioExp1Pin9_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[9]);
}

le_result_t mangoh_gpioExp1Pin9_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[9]);
}

le_result_t mangoh_gpioExp1Pin9_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[9]);
}

bool mangoh_gpioExp1Pin9_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[9]);
}

le_result_t mangoh_gpioExp1Pin9_SetEdgeSense
(
    mangoh_gpioExp1Pin9_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[9], trigger);
}

mangoh_gpioExp1Pin9_Edge_t mangoh_gpioExp1Pin9_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[9]);
}

le_result_t mangoh_gpioExp1Pin9_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[9]);
}

bool mangoh_gpioExp1Pin9_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[9]);
}

bool mangoh_gpioExp1Pin9_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[9]);
}

mangoh_gpioExp1Pin9_Polarity_t mangoh_gpioExp1Pin9_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[9]);
}

bool mangoh_gpioExp1Pin9_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[9]);
}

mangoh_gpioExp1Pin9_PullUpDown_t mangoh_gpioExp1Pin9_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[9]);
}

mangoh_gpioExp1Pin9_ChangeEventHandlerRef_t mangoh_gpioExp1Pin9_AddChangeEventHandler
(
    mangoh_gpioExp1Pin9_Edge_t trigger,
    mangoh_gpioExp1Pin9_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin9_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[9],
        &handlerRecords[9],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin9_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin9_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[9],
        &handlerRecords[9],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 10
le_result_t mangoh_gpioExp1Pin10_SetInput
(
    mangoh_gpioExp1Pin10_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[10], polarity);
}

le_result_t mangoh_gpioExp1Pin10_SetPushPullOutput
(
    mangoh_gpioExp1Pin10_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[10], polarity, value);
}

le_result_t mangoh_gpioExp1Pin10_SetTriStateOutput
(
    mangoh_gpioExp1Pin10_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[10], polarity);
}

le_result_t mangoh_gpioExp1Pin10_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin10_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[10], polarity, value);
}

le_result_t mangoh_gpioExp1Pin10_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[10]);
}

le_result_t mangoh_gpioExp1Pin10_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[10]);
}

le_result_t mangoh_gpioExp1Pin10_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[10]);
}

le_result_t mangoh_gpioExp1Pin10_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[10]);
}

le_result_t mangoh_gpioExp1Pin10_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[10]);
}

le_result_t mangoh_gpioExp1Pin10_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[10]);
}

bool mangoh_gpioExp1Pin10_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[10]);
}

le_result_t mangoh_gpioExp1Pin10_SetEdgeSense
(
    mangoh_gpioExp1Pin10_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[10], trigger);
}

mangoh_gpioExp1Pin10_Edge_t mangoh_gpioExp1Pin10_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[10]);
}

le_result_t mangoh_gpioExp1Pin10_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[10]);
}

bool mangoh_gpioExp1Pin10_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[10]);
}

bool mangoh_gpioExp1Pin10_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[10]);
}

mangoh_gpioExp1Pin10_Polarity_t mangoh_gpioExp1Pin10_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[10]);
}

bool mangoh_gpioExp1Pin10_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[10]);
}

mangoh_gpioExp1Pin10_PullUpDown_t mangoh_gpioExp1Pin10_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[10]);
}

mangoh_gpioExp1Pin10_ChangeEventHandlerRef_t mangoh_gpioExp1Pin10_AddChangeEventHandler
(
    mangoh_gpioExp1Pin10_Edge_t trigger,
    mangoh_gpioExp1Pin10_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin10_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[10],
        &handlerRecords[10],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin10_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin10_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[10],
        &handlerRecords[10],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 11
le_result_t mangoh_gpioExp1Pin11_SetInput
(
    mangoh_gpioExp1Pin11_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[11], polarity);
}

le_result_t mangoh_gpioExp1Pin11_SetPushPullOutput
(
    mangoh_gpioExp1Pin11_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[11], polarity, value);
}

le_result_t mangoh_gpioExp1Pin11_SetTriStateOutput
(
    mangoh_gpioExp1Pin11_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[11], polarity);
}

le_result_t mangoh_gpioExp1Pin11_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin11_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[11], polarity, value);
}

le_result_t mangoh_gpioExp1Pin11_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[11]);
}

le_result_t mangoh_gpioExp1Pin11_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[11]);
}

le_result_t mangoh_gpioExp1Pin11_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[11]);
}

le_result_t mangoh_gpioExp1Pin11_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[11]);
}

le_result_t mangoh_gpioExp1Pin11_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[11]);
}

le_result_t mangoh_gpioExp1Pin11_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[11]);
}

bool mangoh_gpioExp1Pin11_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[11]);
}

le_result_t mangoh_gpioExp1Pin11_SetEdgeSense
(
    mangoh_gpioExp1Pin11_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[11], trigger);
}

mangoh_gpioExp1Pin11_Edge_t mangoh_gpioExp1Pin11_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[11]);
}

le_result_t mangoh_gpioExp1Pin11_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[11]);
}

bool mangoh_gpioExp1Pin11_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[11]);
}

bool mangoh_gpioExp1Pin11_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[11]);
}

mangoh_gpioExp1Pin11_Polarity_t mangoh_gpioExp1Pin11_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[11]);
}

bool mangoh_gpioExp1Pin11_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[11]);
}

mangoh_gpioExp1Pin11_PullUpDown_t mangoh_gpioExp1Pin11_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[11]);
}

mangoh_gpioExp1Pin11_ChangeEventHandlerRef_t mangoh_gpioExp1Pin11_AddChangeEventHandler
(
    mangoh_gpioExp1Pin11_Edge_t trigger,
    mangoh_gpioExp1Pin11_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin11_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[11],
        &handlerRecords[11],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin11_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin11_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[11],
        &handlerRecords[11],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 12
le_result_t mangoh_gpioExp1Pin12_SetInput
(
    mangoh_gpioExp1Pin12_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[12], polarity);
}

le_result_t mangoh_gpioExp1Pin12_SetPushPullOutput
(
    mangoh_gpioExp1Pin12_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[12], polarity, value);
}

le_result_t mangoh_gpioExp1Pin12_SetTriStateOutput
(
    mangoh_gpioExp1Pin12_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[12], polarity);
}

le_result_t mangoh_gpioExp1Pin12_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin12_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[12], polarity, value);
}

le_result_t mangoh_gpioExp1Pin12_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[12]);
}

le_result_t mangoh_gpioExp1Pin12_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[12]);
}

le_result_t mangoh_gpioExp1Pin12_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[12]);
}

le_result_t mangoh_gpioExp1Pin12_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[12]);
}

le_result_t mangoh_gpioExp1Pin12_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[12]);
}

le_result_t mangoh_gpioExp1Pin12_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[12]);
}

bool mangoh_gpioExp1Pin12_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[12]);
}

le_result_t mangoh_gpioExp1Pin12_SetEdgeSense
(
    mangoh_gpioExp1Pin12_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[12], trigger);
}

mangoh_gpioExp1Pin12_Edge_t mangoh_gpioExp1Pin12_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[12]);
}

le_result_t mangoh_gpioExp1Pin12_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[12]);
}

bool mangoh_gpioExp1Pin12_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[12]);
}

bool mangoh_gpioExp1Pin12_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[12]);
}

mangoh_gpioExp1Pin12_Polarity_t mangoh_gpioExp1Pin12_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[12]);
}

bool mangoh_gpioExp1Pin12_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[12]);
}

mangoh_gpioExp1Pin12_PullUpDown_t mangoh_gpioExp1Pin12_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[12]);
}

mangoh_gpioExp1Pin12_ChangeEventHandlerRef_t mangoh_gpioExp1Pin12_AddChangeEventHandler
(
    mangoh_gpioExp1Pin12_Edge_t trigger,
    mangoh_gpioExp1Pin12_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin12_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[12],
        &handlerRecords[12],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin12_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin12_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[12],
        &handlerRecords[12],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 13
le_result_t mangoh_gpioExp1Pin13_SetInput
(
    mangoh_gpioExp1Pin13_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[13], polarity);
}

le_result_t mangoh_gpioExp1Pin13_SetPushPullOutput
(
    mangoh_gpioExp1Pin13_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[13], polarity, value);
}

le_result_t mangoh_gpioExp1Pin13_SetTriStateOutput
(
    mangoh_gpioExp1Pin13_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[13], polarity);
}

le_result_t mangoh_gpioExp1Pin13_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin13_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[13], polarity, value);
}

le_result_t mangoh_gpioExp1Pin13_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[13]);
}

le_result_t mangoh_gpioExp1Pin13_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[13]);
}

le_result_t mangoh_gpioExp1Pin13_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[13]);
}

le_result_t mangoh_gpioExp1Pin13_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[13]);
}

le_result_t mangoh_gpioExp1Pin13_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[13]);
}

le_result_t mangoh_gpioExp1Pin13_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[13]);
}

bool mangoh_gpioExp1Pin13_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[13]);
}

le_result_t mangoh_gpioExp1Pin13_SetEdgeSense
(
    mangoh_gpioExp1Pin13_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[13], trigger);
}

mangoh_gpioExp1Pin13_Edge_t mangoh_gpioExp1Pin13_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[13]);
}

le_result_t mangoh_gpioExp1Pin13_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[13]);
}

bool mangoh_gpioExp1Pin13_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[13]);
}

bool mangoh_gpioExp1Pin13_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[13]);
}

mangoh_gpioExp1Pin13_Polarity_t mangoh_gpioExp1Pin13_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[13]);
}

bool mangoh_gpioExp1Pin13_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[13]);
}

mangoh_gpioExp1Pin13_PullUpDown_t mangoh_gpioExp1Pin13_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[13]);
}

mangoh_gpioExp1Pin13_ChangeEventHandlerRef_t mangoh_gpioExp1Pin13_AddChangeEventHandler
(
    mangoh_gpioExp1Pin13_Edge_t trigger,
    mangoh_gpioExp1Pin13_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin13_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[13],
        &handlerRecords[13],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin13_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin13_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[13],
        &handlerRecords[13],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 14
le_result_t mangoh_gpioExp1Pin14_SetInput
(
    mangoh_gpioExp1Pin14_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[14], polarity);
}

le_result_t mangoh_gpioExp1Pin14_SetPushPullOutput
(
    mangoh_gpioExp1Pin14_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[14], polarity, value);
}

le_result_t mangoh_gpioExp1Pin14_SetTriStateOutput
(
    mangoh_gpioExp1Pin14_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[14], polarity);
}

le_result_t mangoh_gpioExp1Pin14_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin14_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[14], polarity, value);
}

le_result_t mangoh_gpioExp1Pin14_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[14]);
}

le_result_t mangoh_gpioExp1Pin14_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[14]);
}

le_result_t mangoh_gpioExp1Pin14_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[14]);
}

le_result_t mangoh_gpioExp1Pin14_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[14]);
}

le_result_t mangoh_gpioExp1Pin14_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[14]);
}

le_result_t mangoh_gpioExp1Pin14_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[14]);
}

bool mangoh_gpioExp1Pin14_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[14]);
}

le_result_t mangoh_gpioExp1Pin14_SetEdgeSense
(
    mangoh_gpioExp1Pin14_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[14], trigger);
}

mangoh_gpioExp1Pin14_Edge_t mangoh_gpioExp1Pin14_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[14]);
}

le_result_t mangoh_gpioExp1Pin14_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[14]);
}

bool mangoh_gpioExp1Pin14_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[14]);
}

bool mangoh_gpioExp1Pin14_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[14]);
}

mangoh_gpioExp1Pin14_Polarity_t mangoh_gpioExp1Pin14_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[14]);
}

bool mangoh_gpioExp1Pin14_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[14]);
}

mangoh_gpioExp1Pin14_PullUpDown_t mangoh_gpioExp1Pin14_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[14]);
}

mangoh_gpioExp1Pin14_ChangeEventHandlerRef_t mangoh_gpioExp1Pin14_AddChangeEventHandler
(
    mangoh_gpioExp1Pin14_Edge_t trigger,
    mangoh_gpioExp1Pin14_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin14_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[14],
        &handlerRecords[14],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin14_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin14_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[14],
        &handlerRecords[14],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

// GPIO expander #1 GPIO 15
le_result_t mangoh_gpioExp1Pin15_SetInput
(
    mangoh_gpioExp1Pin15_Polarity_t polarity
)
{
    return gpioExpander_SetInput(&expanderPinSpecs[15], polarity);
}

le_result_t mangoh_gpioExp1Pin15_SetPushPullOutput
(
    mangoh_gpioExp1Pin15_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetPushPullOutput(&expanderPinSpecs[15], polarity, value);
}

le_result_t mangoh_gpioExp1Pin15_SetTriStateOutput
(
    mangoh_gpioExp1Pin15_Polarity_t polarity
)
{
    return gpioExpander_SetTriStateOutput(&expanderPinSpecs[15], polarity);
}

le_result_t mangoh_gpioExp1Pin15_SetOpenDrainOutput
(
    mangoh_gpioExp1Pin15_Polarity_t polarity,
    bool value
)
{
    return gpioExpander_SetOpenDrainOutput(&expanderPinSpecs[15], polarity, value);
}

le_result_t mangoh_gpioExp1Pin15_EnablePullUp
(
    void
)
{
    return gpioExpander_EnablePullUp(&expanderPinSpecs[15]);
}

le_result_t mangoh_gpioExp1Pin15_EnablePullDown
(
    void
)
{
    return gpioExpander_EnablePullDown(&expanderPinSpecs[15]);
}

le_result_t mangoh_gpioExp1Pin15_DisableResistors
(
    void
)
{
    return gpioExpander_DisableResistors(&expanderPinSpecs[15]);
}

le_result_t mangoh_gpioExp1Pin15_Activate
(
    void
)
{
    return gpioExpander_Activate(&expanderPinSpecs[15]);
}

le_result_t mangoh_gpioExp1Pin15_Deactivate
(
    void
)
{
    return gpioExpander_Deactivate(&expanderPinSpecs[15]);
}

le_result_t mangoh_gpioExp1Pin15_SetHighZ
(
    void
)
{
    return gpioExpander_SetHighZ(&expanderPinSpecs[15]);
}

bool mangoh_gpioExp1Pin15_Read
(
    void
)
{
    return gpioExpander_Read(&expanderPinSpecs[15]);
}

le_result_t mangoh_gpioExp1Pin15_SetEdgeSense
(
    mangoh_gpioExp1Pin15_Edge_t trigger
)
{
    return gpioExpander_SetEdgeSense(&expanderPinSpecs[15], trigger);
}

mangoh_gpioExp1Pin15_Edge_t mangoh_gpioExp1Pin15_GetEdgeSense
(
    void
)
{
    return gpioExpander_GetEdgeSense(&expanderPinSpecs[15]);
}

le_result_t mangoh_gpioExp1Pin15_DisableEdgeSense
(
    void
)
{
    return gpioExpander_DisableEdgeSense(&expanderPinSpecs[15]);
}

bool mangoh_gpioExp1Pin15_IsOutput
(
    void
)
{
    return gpioExpander_IsOutput(&expanderPinSpecs[15]);
}

bool mangoh_gpioExp1Pin15_IsInput
(
    void
)
{
    return gpioExpander_IsInput(&expanderPinSpecs[15]);
}

mangoh_gpioExp1Pin15_Polarity_t mangoh_gpioExp1Pin15_GetPolarity
(
    void
)
{
    return gpioExpander_GetPolarity(&expanderPinSpecs[15]);
}

bool mangoh_gpioExp1Pin15_IsActive
(
    void
)
{
    return gpioExpander_IsActive(&expanderPinSpecs[15]);
}

mangoh_gpioExp1Pin15_PullUpDown_t mangoh_gpioExp1Pin15_GetPullUpDown
(
    void
)
{
    return gpioExpander_GetPullUpDown(&expanderPinSpecs[15]);
}

mangoh_gpioExp1Pin15_ChangeEventHandlerRef_t mangoh_gpioExp1Pin15_AddChangeEventHandler
(
    mangoh_gpioExp1Pin15_Edge_t trigger,
    mangoh_gpioExp1Pin15_ChangeCallbackFunc_t handlerPtr,
    void *contextPtr,
    int32_t sampleMs
)
{
    return (mangoh_gpioExp1Pin15_ChangeEventHandlerRef_t)gpioExpander_AddChangeEventHandler(
        &expanderPinSpecs[15],
        &handlerRecords[15],
        trigger,
        handlerPtr,
        contextPtr,
        sampleMs);
}

void mangoh_gpioExp1Pin15_RemoveChangeEventHandler
(
    mangoh_gpioExp1Pin15_ChangeEventHandlerRef_t ref
)
{
    gpioExpander_RemoveChangeEventHandler(
        &expanderPinSpecs[15],
        &handlerRecords[15],
        (gpioExpander_ChangeCallbackRef_t)ref);
}

//--------------------------------------------------------------------------------------------------
// END GENERATED CODE
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
/**
 * Interrupt handler for GPIO expander.
 */
//--------------------------------------------------------------------------------------------------
static void gpioExpander_ExpanderInterruptHandler
(
    bool state,       ///< Current state of the GPIO - true: active, false: inactive
    void *contextPtr  ///< Unused
)
{
    gpioExpander_GenericInterruptHandler(0, I2C_SX1509_GPIO_EXPANDER_ADDR, handlerRecords);
}

//--------------------------------------------------------------------------------------------------
/**
 * Get the file handle for the given I2C bus and configure it for access to the given I2C address.
 *
 * @return
 *      - LE_FAULT on failure
 *      - A filehandle to the I2C bus
 *
 * @note
 *      Copied here from gpioExpanderUtils.c.  This function is only required in here because of
 *      the access to the I2C switch (which doesn't belong in here anyway).  This should be removed
 *      later.  Though perhaps this function belongs in a central I2C library since it seems like
 *      it will be required anywhere I2C is used.
 */
//--------------------------------------------------------------------------------------------------
static int I2cAccessBusAddr
(
    uint8_t i2cBus,
    uint8_t i2cAddr
)
{
    const size_t filenameSize = 32;
    char filename[filenameSize];

    snprintf(filename, filenameSize, "/dev/i2c/%d", i2cBus);

    LE_DEBUG("Opening I2C bus: '%s'", filename);
    int fd = open(filename, O_RDWR);
    if (fd < 0 && (errno == ENOENT || errno == ENOTDIR))
    {
        snprintf(filename, filenameSize, "/dev/i2c-%d", i2cBus);
        LE_DEBUG("Opening I2C bus: '%s'", filename);
        fd = open(filename, O_RDWR);
    }

    if (fd < 0)
    {
        if (errno == ENOENT)
        {
            LE_ERROR(
                "Could not open file /dev/i2c-%d or /dev/i2c/%d: %s\n",
                i2cBus,
                i2cBus,
                strerror(ENOENT));
        }
        else
        {
            LE_ERROR("Could not open file %s': %s\n", filename, strerror(errno));
        }

        return LE_FAULT;
    }

    if (ioctl(fd, I2C_SLAVE_FORCE, i2cAddr) < 0)
    {
        LE_ERROR("Could not set address to 0x%02x: %s\n", i2cAddr, strerror(errno));
        return LE_FAULT;
    }

    return fd;
}

#define I2C_SW_PORT_IOT0                     0
#define I2C_SW_PORT_USB_HUB_BATT_CHG         1
#define I2C_SW_PORT_GPIO_EXP1                2
#define I2C_SW_PORT_RASPBERRY_PI_COMP_HDR    3

//--------------------------------------------------------------------------------------------------
/**
 * Initialize the GPIO expander and configure the interrupts.  GPIO expander interrupt
 * pin is connected to a GPIO in the CF3.
 *
 * @todo
 *      This is not the right place to be controlling the I2C switch.  This needs to be managed
 *      centrally.
 */
//--------------------------------------------------------------------------------------------------
COMPONENT_INIT
{
    LE_DEBUG("Enabling PCA9548A I2C switch...");
    const int i2cBus = 0;
    const int i2cdev_fd = I2cAccessBusAddr(i2cBus, I2C_SWITCH_PCA9548A_ADDR);
    LE_FATAL_IF(i2cdev_fd == LE_FAULT, "failed to open i2cbus %d\n", i2cBus);

    // Do not enable battery charger or USB hub ports.  It seems that enabling too many ports
    // simultaneously can lead to i2c communication failures.
    const uint8_t enablePorts = (
        (1 << I2C_SW_PORT_IOT0) |
        (1 << I2C_SW_PORT_USB_HUB_BATT_CHG) |
        (1 << I2C_SW_PORT_GPIO_EXP1) |
        (1 << I2C_SW_PORT_RASPBERRY_PI_COMP_HDR));
    LE_FATAL_IF(i2c_smbus_write_byte(i2cdev_fd, enablePorts) == -1, "failed to write i2c data");

    close(i2cdev_fd);

    // Reset the GPIO expander
    gpioExpander_Reset(0, I2C_SX1509_GPIO_EXPANDER_ADDR);

    // Configure the interrupt for expander
    expanderInterrupt_EnablePullUp();
    expanderInterrupt_SetInput(EXPANDERINTERRUPT_ACTIVE_LOW);
    expanderInterrupt_AddChangeEventHandler(
        EXPANDERINTERRUPT_EDGE_RISING,
        &gpioExpander_ExpanderInterruptHandler,
        NULL,
        100);
}
