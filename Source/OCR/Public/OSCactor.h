// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OSCactor.generated.h"


UCLASS()
class OCR_API AOSCactor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOSCactor();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float ValueX ;

	bool updated = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
		TObjectPtr<class  UOSCServer> Server;
		TObjectPtr<class UOSCManager> manager;
	UPROPERTY(EditAnywhere)
		FString Address;
	UPROPERTY(EditAnywhere)
		int32 Port = 1234;
	UPROPERTY(EditAnywhere)
		FString SName = "";
	
	UFUNCTION()
		void HandleMessage(const struct FOSCMessage& message, const FString& AddressString, int32 portid);
	
};
