// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CalFibonacciTick.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTCASE_API UCalFibonacciTick : public UActorComponent
{
	GENERATED_BODY()
	int f0 = 0;
	int f1 = 1;

public:	
	// Sets default values for this component's properties
	UCalFibonacciTick();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
