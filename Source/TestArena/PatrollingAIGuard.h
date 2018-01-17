// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingAIGuard.generated.h"

/**
 * 
 */
UCLASS()
class TESTARENA_API APatrollingAIGuard : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
	
public:
	//Need to make a get for this
	UPROPERTY(EditInstanceOnly, Category = "Waypoints_CPP")
	TArray<AActor*> Waypoints_CPP;

protected:

private:

	
	
};
