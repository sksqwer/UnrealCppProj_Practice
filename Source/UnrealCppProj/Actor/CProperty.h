// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CProperty.generated.h"

UCLASS()
class UNREALCPPPROJ_API ACProperty : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		int A = 10; 
	UPROPERTY(EditInstanceOnly)
		int B = 20;
	UPROPERTY(EditDefaultsOnly)
		int C;
protected:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int D = 40;
public:	
	// Sets default values for this actor's properties
	ACProperty();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
