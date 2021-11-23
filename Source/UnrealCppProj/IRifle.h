#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IRifle.generated.h"

UINTERFACE(MinimalAPI)
class UIRifle : public UInterface
{
	GENERATED_BODY()
};

class UNREALCPPPROJ_API IIRifle
{
	GENERATED_BODY()
		
public:
	virtual class ACRifle* GetRifle() = 0;

	virtual void GetLocationAndDirection(FVector& outStart, FVector& OutEnd, FVector& OutDirection) = 0;

	virtual void OnFocus() = 0;
	virtual void OffFocus() = 0;
};
