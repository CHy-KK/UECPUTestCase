// Fill out your copyright notice in the Description page of Project Settings.


#include "CalFibonacciTick.h"

// Sets default values for this component's properties
UCalFibonacciTick::UCalFibonacciTick()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCalFibonacciTick::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCalFibonacciTick::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	f1 += f0;
	f0 = f1 - f0;
	f1 %= 10000;
	f0 %= 10000;
#if WITH_EDITOR
	UE_LOG(LogTemp, Log, TEXT("%d, %d"), f0, f1);
#endif

	// ...
}

