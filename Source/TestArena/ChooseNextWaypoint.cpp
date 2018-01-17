// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "PatrollingAIGuard.h" //Need to remove later
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//NEED TO PROTECT Against empty Waypoints

	//Get the waypoints from the Patrolling Guards
	auto AIOwner = OwnerComp.GetAIOwner();													//Return the AI controller from the BehaviorTreeComponent
	auto AIPawn = AIOwner->GetPawn();														//Get the pawn from the AI Controller
	auto AIGuard = Cast<APatrollingAIGuard>(AIPawn);										//Cast the AIPawn to a Patrolling Guard (this is a terrible way to handle getting the waypoints)
	auto waypoints = AIGuard->Waypoints_CPP;												//set the waypoint variable to the AIGuard's waypoint array

	//set the next waypoint
	auto BlackboardComponent = OwnerComp.GetBlackboardComponent();							//Return the blackboard component from the BehaviorTreeComponent
	auto index = BlackboardComponent->GetValueAsInt(Index_Key.SelectedKeyName);				//this returns the value of the Index Key in the Blackboard Category as an Integer
	BlackboardComponent->SetValueAsObject(Waypoint_Key.SelectedKeyName, waypoints[index]);	//Set the waypoint key's value to the index of the waypoint array

	//Iterate/cycle to the next waypoint
	auto waypoint_Length = waypoints.Num();
	auto nextIndex = (index + 1) % waypoint_Length;											//get the next waypoint index
	BlackboardComponent->SetValueAsInt(Index_Key.SelectedKeyName, nextIndex);				//Set the Blackboard value to the next Waypoint Index

	UE_LOG(LogTemp, Warning, TEXT("Waypoint index is: %i"), index);
	return EBTNodeResult::Succeeded;
}

