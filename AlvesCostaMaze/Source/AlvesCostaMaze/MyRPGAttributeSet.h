#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MyRPGAttributeSet.generated.h"

// Macros para ajudar a criar os 'Getters' e 'Setters' automaticamente
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class ALVESCOSTAMAZE_API UMyRPGAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UMyRPGAttributeSet();

	// Define o Atributo "Charge"
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Charge)
	FGameplayAttributeData Charge;
	ATTRIBUTE_ACCESSORS(UMyRPGAttributeSet, Charge);

	// Função necessária para Multiplayer (Replication)
	UFUNCTION()
	virtual void OnRep_Charge(const FGameplayAttributeData& OldCharge);

	// Boilerplate para replicação
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};