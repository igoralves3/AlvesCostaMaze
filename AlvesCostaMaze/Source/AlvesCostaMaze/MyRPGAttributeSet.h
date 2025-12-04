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
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	UMyRPGAttributeSet();

	// Define o Atributo "Charge"
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Charge)
	FGameplayAttributeData Charge;
	ATTRIBUTE_ACCESSORS(UMyRPGAttributeSet, Charge);

	// Função necessária para Multiplayer (Replication)
	UFUNCTION()
	virtual void OnRep_Charge(const FGameplayAttributeData& OldCharge);


	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Speed)
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UMyRPGAttributeSet, Speed)
	
	UFUNCTION()
	virtual void OnRep_Speed(const FGameplayAttributeData& OldSpeed);
	// Vida Atual
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UMyRPGAttributeSet, Health);

	// Vida Máxima (Para limitar a cura)
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UMyRPGAttributeSet, MaxHealth);

	// Funções de Replicação
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	// Função Extra: Para garantir que a vida nunca fique negativa ou maior que o máximo
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	// Boilerplate para replicação
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};