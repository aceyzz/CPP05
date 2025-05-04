<img src="git_utils/banner.png" width= 100%>

<br>

---

<br>

<details>
<summary>FRENCH VERSION</summary>

## Exercice 00 - "Mommy, when I grow up, I want to be a bureaucrat!"

<details>
  <summary>Afficher/Masquer</summary>

#### Objectif :
L'objectif de cet exercice est de concevoir une classe `Bureaucrat` qui incarne le concept de bureaucratie avec des règles strictes concernant le grade des bureaucrates. Les bureaucrates ont un grade numérique qui détermine leur rang dans la hiérarchie bureaucratique, avec 1 étant le grade le plus élevé et 150 le plus bas.

#### Contraintes :
- **Nom Constant** : Chaque bureaucrate possède un nom qui ne change pas.
- **Grade** : Le grade est compris entre 1 et 150. Toute tentative de création d'un bureaucrate avec un grade en dehors de cette plage doit lever une exception.
- **Gestion des Exceptions** : Deux types d'exceptions doivent être gérés - `GradeTooHighException` et `GradeTooLowException`, pour les cas où le grade est respectivement trop haut ou trop bas.
- **Manipulation des Grades** : Il doit être possible d'incrémenter ou de décrémenter le grade d'un bureaucrate, avec gestion des exceptions si les modifications proposées font sortir le grade de la plage valide.
- **Affichage** : Implémenter une surcharge de l'opérateur d'insertion (<<) pour afficher les détails d'un bureaucrate sous la forme : `<nom>, bureaucrate grade <grade>`.

### Mon Implémentation :

[Lien ici](https://github.com/aceyzz/CPP05/tree/main/ex00)

#### Classe Bureaucrat :
- **Attributs** : 
  - `const std::string _name` : Le nom du bureaucrate, constant et initialisé lors de la création.
  - `int _grade` : Le grade du bureaucrate, doit être entre 1 et 150.

- **Constructeurs et Destructeur** : 
  - Un constructeur par défaut, un constructeur paramétrique pour initialiser le bureaucrate avec un nom et un grade spécifiques, et un destructeur.
  - Le constructeur paramétrique vérifie la validité du grade et lance des exceptions si nécessaire.

- **Exceptions** : 
  - `GradeTooHighException` et `GradeTooLowException` sont définies comme des classes internes, héritant de `std::exception`, et implémentant la méthode `what()` pour fournir un message d'erreur.

- **Fonctionnalités** :
  - `incrementGrade()` et `decrementGrade()` pour modifier le grade du bureaucrate, avec gestion des exceptions si le grade résultant est invalide.
  - `getName()` et `getGrade()` comme accesseurs pour obtenir le nom et le grade du bureaucrate.

- **Surcharge de l'Opérateur <<** :
  - Permet d'afficher les informations du bureaucrate en utilisant `std::cout`.

#### Gestion des Exceptions :
Des blocs `try` et `catch` sont utilisés pour capturer et gérer les exceptions lors de la manipulation des grades des bureaucrates. Cela inclut les tentatives d'augmentation ou de diminution du grade au-delà des limites autorisées.

#### Test :
Des instances de `Bureaucrat` sont créées avec différents grades pour démontrer la gestion des exceptions et l'affichage des informations du bureaucrate. Les tests mettent en évidence la robustesse de la classe face aux opérations invalides.

</details>

<br>

---

<br>

## Exercice 01 - "Form up, maggots!"

<details>
  <summary>Afficher/Masquer</summary>

#### Objectif :
Après l'introduction des bureaucrates, cet exercice propose de leur attribuer des tâches à travers la gestion de formulaires à remplir. La classe `Form` représente ces formulaires et contient les éléments suivants :
- **Nom Constant** : Un nom immuable pour le formulaire.
- **Statut de Signature** : Un booléen indiquant si le formulaire est signé ou non (non signé par défaut).
- **Grade Requis pour Signature** : Un grade spécifique requis pour pouvoir signer le formulaire.
- **Grade Requis pour Exécution** : Un grade spécifique requis pour pouvoir exécuter le formulaire.

#### Contraintes :
- Les grades des formulaires suivent les mêmes règles que ceux des bureaucrates, avec gestion des exceptions `Form::GradeTooHighException` et `Form::GradeTooLowException` si un grade est hors limites.
- La classe `Form` doit fournir des accesseurs pour tous ses attributs et une surcharge de l'opérateur d'insertion (<<) pour afficher les informations du formulaire.
- La fonction membre `beSigned(Bureaucrat)` permet de changer le statut du formulaire en "signé" si le grade du bureaucrate est suffisant.

#### Classe Bureaucrat :
- Modification pour inclure la fonction membre `signForm(Form&)` qui tente de signer un formulaire. Si le formulaire est signé avec succès, un message de confirmation est affiché ; sinon, une raison est donnée pour l'échec.

### Mon Implémentation :

[Lien ici](https://github.com/aceyzz/CPP05/tree/main/ex01)

#### Classe Form :
- **Constructeurs et Destructeur** : 
  - Un constructeur par défaut, un constructeur paramétrique pour initialiser le formulaire avec des grades spécifiques pour la signature et l'exécution, et un destructeur.
- **Exceptions** : 
  - Des exceptions personnalisées `GradeTooHighException` et `GradeTooLowException` pour gérer les grades invalides lors de la création des formulaires.
- **Fonctionnalités** :
  - `beSigned(const Bureaucrat&)` pour tenter de signer le formulaire avec un bureaucrate donné, avec gestion des exceptions si le grade du bureaucrate est insuffisant.

#### Modifications de la Classe Bureaucrat :
- Ajout de la fonction `signForm(Form&)` qui permet au bureaucrate de signer un formulaire, affichant un message selon que la signature est réussie ou non.

#### Test :
Des scénarios de test sont implémentés pour démontrer la création de formulaires, la gestion des exceptions liées aux grades, et l'interaction entre bureaucrates et formulaires pour la signature. Ces tests mettent en lumière le fonctionnement intégré des classes `Bureaucrat` et `Form` dans le contexte de la gestion des documents administratifs.

</details>

<br>

---

<br>

## Exercice 02 - "No, you need form 28B, not 28C..."

<details>
  <summary>Afficher/Masquer</summary>

#### Objectif :
L'objectif est d'introduire des formulaires concrets qui effectuent des actions spécifiques, en transformant la classe de base `Form` en une classe abstraite renommée `AForm`. Cette transformation implique que tous les attributs restent privés dans la classe de base.

#### Formulaires Concrets :
- **ShrubberyCreationForm** : Crée un fichier `<target>_shrubbery` et y écrit des arbres en ASCII. Grades requis : signature 145, exécution 137.
- **RobotomyRequestForm** : Produit des bruits de perçage et annonce la robotomisation réussie de `<target>` 50% du temps. Sinon, informe de l'échec. Grades requis : signature 72, exécution 45.
- **PresidentialPardonForm** : Annonce que `<target>` a été gracié par Zaphod Beeblebrox. Grades requis : signature 25, exécution 5.

Chaque formulaire prend en paramètre de son constructeur la cible du formulaire (par exemple, "home" pour planter un arbuste à domicile).

#### Exécution des Formulaires :
- Une fonction membre `execute(Bureaucrat const &executor) const` est ajoutée à la classe de base pour exécuter l'action spécifique du formulaire. Cette fonction vérifie si le formulaire est signé et si le grade du bureaucrate tentant d'exécuter le formulaire est suffisamment élevé, sinon elle lance une exception appropriée.

#### Classe Bureaucrat :
- Ajout de la fonction membre `executeForm(AForm const &form)` qui tente d'exécuter le formulaire. Si l'exécution est réussie, elle affiche un message de confirmation; sinon, elle affiche un message d'erreur explicite.

### Mon Implémentation :

[Lien ici](https://github.com/aceyzz/CPP05/tree/main/ex02)

#### Modifications et Ajouts :
- **Classe AForm** : Renommage de `Form` en `AForm` pour indiquer son caractère abstrait, avec l'ajout de la fonction virtuelle pure `execute` pour exécuter l'action du formulaire.
- **Classes de Formulaires Spécifiques** : Implémentation des classes `ShrubberyCreationForm`, `RobotomyRequestForm`, et `PresidentialPardonForm` avec leurs comportements d'exécution uniques.
- **Gestion des Exceptions** : Ajout de gestion des exceptions pour garantir que les formulaires ne soient exécutés que si les conditions requises sont remplies (formulaire signé, grade suffisant).

#### Tests :
Des scénarios de test démontrent la création et l'exécution de chaque type de formulaire, illustrant la flexibilité et l'extensibilité du système de formulaires grâce à l'héritage et au polymorphisme. Ces tests mettent en évidence les interactions entre les bureaucrates et les divers formulaires, soulignant la complexité et la robustesse de la gestion des formulaires dans le cadre bureaucratique.

</details>

<br>

---

<br>


## Exercice 03 - "At least this beats coffee-making"

<details>
  <summary>Afficher/Masquer</summary>

#### Objectif :
Dans cet exercice, l'objectif est de mettre en œuvre la classe `Intern`, qui a la capacité unique de créer des formulaires. Les stagiaires n'ont pas de nom, de grade ou de caractéristiques uniques ; leur seule responsabilité est de faire leur travail, c'est-à-dire de générer des formulaires.

#### Fonctionnement de l'Intern :
- La fonction principale de l'`Intern` est `makeForm()`, qui prend deux chaînes de caractères : le nom du formulaire et sa cible. Elle renvoie un pointeur sur un objet `Form` dont le nom est celui passé en paramètre et dont la cible est initialisée au second paramètre.
- Si le nom du formulaire donné n'existe pas, l'intern doit afficher un message d'erreur explicite.

### Mon Implémentation :

[Lien ici](https://github.com/aceyzz/CPP05/tree/main/ex03)

#### Classe Intern :
- **Méthode makeForm()** : Cette méthode crée dynamiquement une instance de `Form` basée sur le nom du formulaire demandé. Elle utilise une approche flexible pour déterminer quel type de formulaire créer, évitant ainsi une cascade de `if/else` ou un `switch` peu élégant.
- **Gestion des Exceptions** : Une exception personnalisée `NoValidFormException` est lancée si le nom du formulaire fourni ne correspond à aucun formulaire connu de l'intern. Cela garantit que seuls des formulaires valides peuvent être créés.

#### Tests :
Le code de test démontre la création d'un `RobotomyRequestForm` ciblant "`Bender`" par l'intern, illustrant l'efficacité et la simplicité de la méthode `makeForm()` pour générer divers types de formulaires.

Cet exercice illustre le principe de délégation des tâches à un intern pour la création de formulaires, soulignant l'importance de la modularité et de la gestion des exceptions dans la conception logicielle. Les tests effectués démontrent la polyvalence de l'intern dans la création de formulaires spécifiques à la demande, tout en assurant une gestion robuste des cas d'erreur.

</details>

<br>

</details>

<br>

---

<br>

<details>
<summary>ENGLISH VERSION</summary>

## Exercise 00 - "Mommy, when I grow up, I want to be a bureaucrat!"

<details>
	<summary>Show/Hide</summary>

#### Objective:
The goal of this exercise is to design a `Bureaucrat` class that embodies the concept of bureaucracy with strict rules regarding bureaucrats' grades. Bureaucrats have a numerical grade that determines their rank in the bureaucratic hierarchy, with 1 being the highest grade and 150 the lowest.

#### Constraints:
- **Constant Name**: Each bureaucrat has a name that does not change.
- **Grade**: The grade is between 1 and 150. Any attempt to create a bureaucrat with a grade outside this range must throw an exception.
- **Exception Handling**: Two types of exceptions must be handled - `GradeTooHighException` and `GradeTooLowException`, for cases where the grade is too high or too low, respectively.
- **Grade Manipulation**: It must be possible to increment or decrement a bureaucrat's grade, with exception handling if the proposed changes result in an invalid grade.
- **Display**: Implement an overload of the insertion operator (<<) to display the details of a bureaucrat in the format: `<name>, bureaucrat grade <grade>`.

### My Implementation:

[Link here](https://github.com/aceyzz/CPP05/tree/main/ex00)

#### Bureaucrat Class:
- **Attributes**: 
	- `const std::string _name`: The bureaucrat's name, constant and initialized at creation.
	- `int _grade`: The bureaucrat's grade, must be between 1 and 150.

- **Constructors and Destructor**: 
	- A default constructor, a parameterized constructor to initialize the bureaucrat with a specific name and grade, and a destructor.
	- The parameterized constructor checks the validity of the grade and throws exceptions if necessary.

- **Exceptions**: 
	- `GradeTooHighException` and `GradeTooLowException` are defined as inner classes, inheriting from `std::exception`, and implementing the `what()` method to provide an error message.

- **Features**:
	- `incrementGrade()` and `decrementGrade()` to modify the bureaucrat's grade, with exception handling if the resulting grade is invalid.
	- `getName()` and `getGrade()` as accessors to retrieve the bureaucrat's name and grade.

- **Overload of the << Operator**:
	- Allows displaying the bureaucrat's information using `std::cout`.

#### Exception Handling:
`try` and `catch` blocks are used to capture and handle exceptions when manipulating bureaucrats' grades. This includes attempts to increase or decrease the grade beyond the allowed limits.

#### Test:
Instances of `Bureaucrat` are created with different grades to demonstrate exception handling and the display of bureaucrat information. The tests highlight the robustness of the class against invalid operations.

</details>

<br>

---

<br>

## Exercise 01 - "Form up, maggots!"

<details>
	<summary>Show/Hide</summary>

#### Objective:
After introducing bureaucrats, this exercise assigns them tasks through the management of forms to be filled out. The `Form` class represents these forms and includes the following elements:
- **Constant Name**: An immutable name for the form.
- **Signature Status**: A boolean indicating whether the form is signed or not (unsigned by default).
- **Grade Required for Signing**: A specific grade required to sign the form.
- **Grade Required for Execution**: A specific grade required to execute the form.

#### Constraints:
- Form grades follow the same rules as bureaucrats, with exception handling for `Form::GradeTooHighException` and `Form::GradeTooLowException` if a grade is out of bounds.
- The `Form` class must provide accessors for all its attributes and an overload of the insertion operator (<<) to display the form's information.
- The member function `beSigned(Bureaucrat)` allows changing the form's status to "signed" if the bureaucrat's grade is sufficient.

#### Bureaucrat Class:
- Modified to include the member function `signForm(Form&)` which attempts to sign a form. If the form is successfully signed, a confirmation message is displayed; otherwise, a reason for the failure is given.

### My Implementation:

[Link here](https://github.com/aceyzz/CPP05/tree/main/ex01)

#### Form Class:
- **Constructors and Destructor**: 
	- A default constructor, a parameterized constructor to initialize the form with specific grades for signing and execution, and a destructor.
- **Exceptions**: 
	- Custom exceptions `GradeTooHighException` and `GradeTooLowException` to handle invalid grades when creating forms.
- **Features**:
	- `beSigned(const Bureaucrat&)` to attempt to sign the form with a given bureaucrat, with exception handling if the bureaucrat's grade is insufficient.

#### Modifications to the Bureaucrat Class:
- Added the `signForm(Form&)` function that allows the bureaucrat to sign a form, displaying a message depending on whether the signature is successful or not.

#### Test:
Test scenarios are implemented to demonstrate the creation of forms, exception handling related to grades, and the interaction between bureaucrats and forms for signing. These tests highlight the integrated functionality of the `Bureaucrat` and `Form` classes in the context of administrative document management.

</details>

<br>

---

<br>

## Exercise 02 - "No, you need form 28B, not 28C..."

<details>
	<summary>Show/Hide</summary>

#### Objective:
The goal is to introduce concrete forms that perform specific actions by transforming the base `Form` class into an abstract class renamed `AForm`. This transformation ensures that all attributes remain private in the base class.

#### Concrete Forms:
- **ShrubberyCreationForm**: Creates a `<target>_shrubbery` file and writes ASCII trees in it. Required grades: signing 145, execution 137.
- **RobotomyRequestForm**: Produces drilling noises and announces the successful robotomization of `<target>` 50% of the time. Otherwise, it informs of the failure. Required grades: signing 72, execution 45.
- **PresidentialPardonForm**: Announces that `<target>` has been pardoned by Zaphod Beeblebrox. Required grades: signing 25, execution 5.

Each form takes the target of the form as a parameter in its constructor (e.g., "home" to plant a shrub at home).

#### Form Execution:
- A member function `execute(Bureaucrat const &executor) const` is added to the base class to execute the form's specific action. This function checks if the form is signed and if the grade of the bureaucrat attempting to execute the form is high enough; otherwise, it throws an appropriate exception.

#### Bureaucrat Class:
- Added the member function `executeForm(AForm const &form)` which attempts to execute the form. If the execution is successful, it displays a confirmation message; otherwise, it displays an explicit error message.

### My Implementation:

[Link here](https://github.com/aceyzz/CPP05/tree/main/ex02)

#### Modifications and Additions:
- **AForm Class**: Renamed `Form` to `AForm` to indicate its abstract nature, with the addition of the pure virtual function `execute` to perform the form's action.
- **Specific Form Classes**: Implementation of the `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm` classes with their unique execution behaviors.
- **Exception Handling**: Added exception handling to ensure that forms are only executed if the required conditions are met (form signed, sufficient grade).

#### Tests:
Test scenarios demonstrate the creation and execution of each type of form, illustrating the flexibility and extensibility of the form system through inheritance and polymorphism. These tests highlight the interactions between bureaucrats and various forms, emphasizing the complexity and robustness of form management in a bureaucratic framework.

</details>

<br>

---

<br>


## Exercise 03 - "At least this beats coffee-making"

<details>
	<summary>Show/Hide</summary>

#### Objective:
In this exercise, the goal is to implement the `Intern` class, which has the unique ability to create forms. Interns have no name, grade, or unique characteristics; their sole responsibility is to do their job, which is to generate forms.

#### Intern Functionality:
- The main function of the `Intern` is `makeForm()`, which takes two strings: the name of the form and its target. It returns a pointer to a `Form` object whose name matches the one provided and whose target is initialized to the second parameter.
- If the given form name does not exist, the intern must display an explicit error message.

### My Implementation:

[Link here](https://github.com/aceyzz/CPP05/tree/main/ex03)

#### Intern Class:
- **makeForm() Method**: This method dynamically creates an instance of `Form` based on the requested form name. It uses a flexible approach to determine which type of form to create, avoiding an inelegant cascade of `if/else` or a `switch`.
- **Exception Handling**: A custom exception `NoValidFormException` is thrown if the provided form name does not match any form known to the intern. This ensures that only valid forms can be created.

#### Tests:
The test code demonstrates the creation of a `RobotomyRequestForm` targeting "`Bender`" by the intern, illustrating the efficiency and simplicity of the `makeForm()` method for generating various types of forms.

This exercise illustrates the principle of delegating tasks to an intern for form creation, emphasizing the importance of modularity and exception handling in software design. The tests performed demonstrate the intern's versatility in creating specific forms on demand while ensuring robust error handling.

</details>

<br>

</details>
