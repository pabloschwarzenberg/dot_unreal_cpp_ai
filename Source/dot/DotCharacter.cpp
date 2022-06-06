// Fill out your copyright notice in the Description page of Project Settings.


#include "DotCharacter.h"
#include "DotAnimInstance.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimInstance.h"
#include "Math/UnrealMathUtility.h"
#include "Math/Vector.h"

// Sets default values
ADotCharacter::ADotCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    animBP=nullptr;
    bUseControllerRotationYaw = false;
    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll = false;
    UCharacterMovementComponent* mc = GetCharacterMovement();
    if (mc)
        mc->bUseControllerDesiredRotation = false;
    flores=0;
    frutos=0;
    UCapsuleComponent* capsula;
    capsula=GetCapsuleComponent();
    capsula->OnComponentBeginOverlap.AddDynamic(this, &ADotCharacter::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ADotCharacter::BeginPlay()
{
	Super::BeginPlay();
    UAnimInstance* anim;
    USkeletalMeshComponent* mesh;
    
    mesh=GetMesh();
    anim=mesh->GetAnimInstance();
    animBP=Cast<UDotAnimInstance>(anim);
    if(animBP)
    {
        animBP->isJumping=false;
        animBP->isCrouching=false;
        animBP->isMoving=false;
        animBP->isSwimming=false;
    }
}

// Called every frame
void ADotCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADotCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    InputComponent->BindAxis("Forward", this, &ADotCharacter::MoveX);
    InputComponent->BindAxis("Back", this, &ADotCharacter::MoveY);
    InputComponent->BindAction( "Crouch", IE_Pressed, this,
    &ADotCharacter::DotCrouch );
    InputComponent->BindAction( "Crouch", IE_Released, this,
    &ADotCharacter::DotCrouchStop );
    InputComponent->BindAction( "Jump", IE_Pressed, this,
    &ADotCharacter::DotJump );
}

void ADotCharacter::MoveY(float delta)
{
    if( Controller && delta )
    {
        FVector heading(0,1,0);
        USkeletalMeshComponent* mesh;
        mesh=GetMesh();
        AddMovementInput(heading, delta);
        animBP->isMoving=true;
        if (delta>0) {
            mesh->SetWorldRotation(FRotator(0,0,0));
        } else {
            mesh->SetWorldRotation(FRotator(0,180,0));
        }
    }
}

void ADotCharacter::MoveX(float delta)
{
    FVector velocidad=GetVelocity();
    float rapidez=FVector::DotProduct(velocidad,velocidad);
    if(rapidez==0)
        animBP->isMoving=false;
    if(Controller && delta)
    {
        FVector fwd = GetActorForwardVector();
        USkeletalMeshComponent* mesh;
        mesh=GetMesh();
        AddMovementInput(fwd,delta);
        animBP->isMoving=true;
        if (delta>0) {
            mesh->SetWorldRotation(FRotator(0,-90,0));
        } else {
            mesh->SetWorldRotation(FRotator(0,90,0));
        }
    }
}

void ADotCharacter::DotCrouch()
{
    animBP->isCrouching=true;
}

void ADotCharacter::DotCrouchStop()
{
    animBP->isCrouching=false;
}

void ADotCharacter::DotJump()
{
    animBP->isJumping=true;
    Jump();
}

void ADotCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,AActor* OtherActor,
                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                    const FHitResult& Sweep)
{
    ADotItem* item;
    item=Cast<ADotItem>(OtherActor);
    if(item)
    {
        AFrutoDotItem* fruto=Cast<AFrutoDotItem>(item);
        if(fruto)
            frutos++;
        else
        {
            AFlorDotItem* flor=Cast<AFlorDotItem>(item);
            if(flor)
                flores++;
        }
        item->Destroy();
    }
}
