// Fill out your copyright notice in the Description page of Project Settings.
#include "OSCactor.h"
#include "Kismet/KismetStringLibrary.h"
#include "OSCManager.h"
#include "OSCMessage.h"
#include "OSCServer.h"

// Sets default values
AOSCactor::AOSCactor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOSCactor::BeginPlay()
{
	Super::BeginPlay();
	manager = NewObject<UOSCManager>(this,UOSCManager::StaticClass());
	Server = manager->CreateOSCServer(Address,Port,false,true,SName);

	if(Server)
	{
		Server->OnOscMessageReceived.AddDynamic(this,&AOSCactor::HandleMessage);
	}
	
}

// Called every frame
void AOSCactor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AOSCactor::HandleMessage(const FOSCMessage& message, const FString& AddressString, int32 portid)
{
	updated = false;
	struct FOSCAddress myaddress = message.GetAddress();
	FString myaddressstring = myaddress.GetFullPath();
	FString FirstPart;
	FString SecondPart;
	FString Case;
	if (UKismetStringLibrary::Split(myaddressstring, TEXT("/"), FirstPart, SecondPart))
	{
		UKismetStringLibrary::Split(SecondPart, TEXT("/"), FirstPart, SecondPart);
		Case = SecondPart;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Second Part: %s"), *SecondPart));	
	}
	
	if (Case == TEXT("accel"))
	{
		
		(manager->GetFloat(message, 0, ValueX));
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%f"), ValueX));
		if(ValueX < -0.5)
		{
			ValueX *= -1;
			updated = true;
		}
		else ValueX = 0;
	}
}


