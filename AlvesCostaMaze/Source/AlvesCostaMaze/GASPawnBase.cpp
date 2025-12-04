#include "GASPawnBase.h"
#include "AbilitySystemComponent.h"
#include "MyRPGAttributeSet.h" // Inclua o header dos seus atributos

AGASPawnBase::AGASPawnBase()
{
	// Cria o componente do sistema
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComp"));

	// Cria os atributos (AQUI ESTÁ A MÁGICA QUE FALTAVA)
	Attributes = CreateDefaultSubobject<UMyRPGAttributeSet>(TEXT("Attributes"));
}

UAbilitySystemComponent* AGASPawnBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}