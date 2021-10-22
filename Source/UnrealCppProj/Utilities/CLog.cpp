// Fill out your copyright notice in the Description page of Project Settings.


#include "CLog.h"
#include "Engine.h"

DEFINE_LOG_CATEGORY_STATIC(GameObject, Display, All)

void CLog::Print(int32 InValue, int32 InKey, float Duration, FColor	inColor)
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

void CLog::Log(int32 InValue)
{
	UE_LOG(GameObject, Display, L"%d", InValue);
}

void CLog::Log(float InValue)
{
	UE_LOG(GameObject, Display, L"%f", InValue);
}

void CLog::Log(const FString& InValue)
{
	UE_LOG(GameObject, Display, L"%s", *InValue);
}

void CLog::Log(const FVector& InValue)
{
	UE_LOG(GameObject, Display, L"%s", *InValue.ToString());
}

void CLog::Log(const FRotator& InValue)
{
	UE_LOG(GameObject, Display, L"%s", *InValue.ToString());
}

void CLog::Log(const UObject* InObject)
{
	FString str;
	if (!!InObject)
		str.Append(InObject->GetName());
	str.Append(!!InObject ? " Is Not Null" : " Is Null");
	UE_LOG(GameObject, Display, L"%s", *str);
}

void CLog::Log(const FString& InFuncName, int32 InLineNumber)
{
	FString str;
	str.Append(InFuncName);
	str.Append(" , ");
	str.Append(FString::FromInt(InLineNumber));
	UE_LOG(GameObject, Display, L"%s", *str);
}
