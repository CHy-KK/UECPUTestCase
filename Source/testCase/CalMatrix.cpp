// Fill out your copyright notice in the Description page of Project Settings.


#include "CalMatrix.h"

// Sets default values for this component's properties
UCalMatrix::UCalMatrix()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCalMatrix::BeginPlay()
{
	Super::BeginPlay();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m1.M[i][j] = FMath::FRandRange(0.01f, 0.99f);
			m2.M[i][j] = FMath::FRandRange(0.01f, 0.99f);
		}
	}
	// ...
	
}


// Called every frame
void UCalMatrix::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	m1 *= m2;
	m2 *= m1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m1.M[i][j] = FMath::Fractional(m1.M[i][j]);
			m2.M[i][j] = FMath::Fractional(m1.M[i][j]);
		}
	}
#if WITH_EDITOR
	for (int i = 0; i < 4; i++) {
		UE_LOG(LogTemp, Log, TEXT("%f %f %f %f\n"), m1.M[i][0], m1.M[i][1], m1.M[i][2], m1.M[i][3]);
	}
	for (int i = 0; i < 4; i++) {
		UE_LOG(LogTemp, Log, TEXT("%f %f %f %f\n"), m2.M[i][0], m2.M[i][1], m2.M[i][2], m2.M[i][3]);
	}
#endif
	// ...
}

