// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CCylinder.generated.h"

UCLASS()
class UNREALCPPPROJ_API ACCylinder : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleDefaultsOnly)
		class USceneComponent* Scene;

	UPROPERTY(VisibleDefaultsOnly)
		class UTextRenderComponent* Text;

	UPROPERTY(VisibleDefaultsOnly)
		class UStaticMeshComponent* Mesh;

	
public:	
	// Sets default values for this actor's properties
	ACCylinder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

};
