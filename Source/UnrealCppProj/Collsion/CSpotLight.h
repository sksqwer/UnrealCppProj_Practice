// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSpotLight.generated.h"

UCLASS()
class UNREALCPPPROJ_API ACSpotLight : public AActor
{
	GENERATED_BODY()
	
public:	
	ACSpotLight();


private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class USpotLightComponent* SpotLights[3];

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

private:
	UFUNCTION()
		void OnMyColor(int32 InIndex, FLinearColor InColor);


protected:
	virtual void BeginPlay() override;
	

};
