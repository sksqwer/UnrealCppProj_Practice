#pragma once
#include "CoreMinimal.h"
#include "UObject/ConstructorHelpers.h"

class UNREALCPPPROJ_API CHelpers
{
public:
	template<typename T> static void GetAsset(T** outObject, FString inPath)
	{
		ConstructorHelpers::FObjectFinder<T> asset(*inPath);
		verifyf(asset.Succeeded(), L"asset.Succeeded()");
		*outObject = asset.Object;
	}
};