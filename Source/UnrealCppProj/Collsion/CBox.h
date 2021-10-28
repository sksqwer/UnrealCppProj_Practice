// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBox.generated.h"

UCLASS()
class UNREALCPPPROJ_API ACBox : public AActor
{
	GENERATED_BODY()
	
public:	
	ACBox();


private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh[3];

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

private:
	UFUNCTION()
		void OnPhysics(int32 InIndex, FLinearColor InColor);


protected:
	virtual void BeginPlay() override;

private:
	UMaterialInstanceDynamic*	Material[3];
	FVector						WorldLocation[3];

};
