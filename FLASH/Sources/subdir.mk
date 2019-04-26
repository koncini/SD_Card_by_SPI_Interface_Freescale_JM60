################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Fat.c" \
"../Sources/Nokia5110.c" \
"../Sources/SD.c" \
"../Sources/SPI.c" \
"../Sources/glcdfont.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/Fat.c \
../Sources/Nokia5110.c \
../Sources/SD.c \
../Sources/SPI.c \
../Sources/glcdfont.c \
../Sources/main.c \

OBJS += \
./Sources/Fat_c.obj \
./Sources/Nokia5110_c.obj \
./Sources/SD_c.obj \
./Sources/SPI_c.obj \
./Sources/glcdfont_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/Fat_c.obj" \
"./Sources/Nokia5110_c.obj" \
"./Sources/SD_c.obj" \
"./Sources/SPI_c.obj" \
"./Sources/glcdfont_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/Fat_c.d \
./Sources/Nokia5110_c.d \
./Sources/SD_c.d \
./Sources/SPI_c.d \
./Sources/glcdfont_c.d \
./Sources/main_c.d \

C_DEPS_QUOTED += \
"./Sources/Fat_c.d" \
"./Sources/Nokia5110_c.d" \
"./Sources/SD_c.d" \
"./Sources/SPI_c.d" \
"./Sources/glcdfont_c.d" \
"./Sources/main_c.d" \

OBJS_OS_FORMAT += \
./Sources/Fat_c.obj \
./Sources/Nokia5110_c.obj \
./Sources/SD_c.obj \
./Sources/SPI_c.obj \
./Sources/glcdfont_c.obj \
./Sources/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Fat_c.obj: ../Sources/Fat.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Fat.args" -ObjN="Sources/Fat_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Nokia5110_c.obj: ../Sources/Nokia5110.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/Nokia5110.args" -ObjN="Sources/Nokia5110_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/SD_c.obj: ../Sources/SD.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/SD.args" -ObjN="Sources/SD_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/SPI_c.obj: ../Sources/SPI.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/SPI.args" -ObjN="Sources/SPI_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/glcdfont_c.obj: ../Sources/glcdfont.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/glcdfont.args" -ObjN="Sources/glcdfont_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


