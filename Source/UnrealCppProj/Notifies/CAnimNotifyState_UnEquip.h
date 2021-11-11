#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "CAnimNotifyState_UnEquip.generated.h"

UCLASS()
class UNREALCPPPROJ_API UCAnimNotifyState_UnEquip : public UAnimNotifyState
{
	GENERATED_BODY()
		FString GetNotifyName_Implementation() const;
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
	
};
