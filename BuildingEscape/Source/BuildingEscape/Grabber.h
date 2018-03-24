// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
// #include "Components/InputComponent.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
private:
	// How far ahead can the player reach in CM
	float Reach = 100.0f;

	UPhysicsHandleComponent * PhysicsHandle = nullptr;

	UInputComponent * InputComponent = nullptr;

	// Ray-Cast and grab what's in reach
	void Grab();

	// called when grab is realeased
	void Release();

	void FindPhysicsHandleComponent();
	void SetupInputComponent();
		
	// Return HIT for first pyhsics body reached
	const FHitResult GetFirstPhysicsBodyInReach();

	FVector GetReachLineStart() const;
	FVector GetReachLineEnd() const;
	
};