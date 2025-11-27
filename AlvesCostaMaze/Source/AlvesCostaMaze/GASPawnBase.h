#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AbilitySystemInterface.h" // Importante!
#include "GASPawnBase.generated.h"

UCLASS()
class ALVESCOSTAMAZE_API AGASPawnBase : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGASPawnBase();

	// O Componente do GAS
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	class UAbilitySystemComponent* AbilitySystemComponent;

	// Os Atributos (Charge, etc)
	UPROPERTY()
	class UMyRPGAttributeSet* Attributes;

	// Função obrigatória para o GAS funcionar
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};