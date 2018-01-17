// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class TESTARENA_API UChooseNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:

protected:
	//this exposes a blackboard key selector in Blueprint under the category of Blackboard and with the name of Index Selector
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector Index_Key;
	
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector Waypoint_Key;
};
