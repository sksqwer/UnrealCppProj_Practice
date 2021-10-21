// Fill out your copyright notice in the Description page of Project Settings.


#include "CLog.h"
#include "Engine.h"

void CLog::Print(int32& InValue, int32 InKey, float Duration, FColor	inColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, inColor,
		FString::FromInt(InValue));
}

void CLog::Print(float& InValue, int32 InKey, float Duration, FColor inColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, inColor,
		FString::SanitizeFloat(InValue));
}

void CLog::Print(const FString& InValue, int32 InKey, float Duration, FColor inColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, inColor,
		InValue);
}

void CLog::Print(const FVector& InValue, int32 InKey, float Duration, FColor inColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, inColor,
		InValue.ToString());
}

void CLog::Print(const FRotator& InValue, int32 InKey, float Duration, FColor inColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, inColor,
		InValue.ToString());
}
