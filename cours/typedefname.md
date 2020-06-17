## Typename & Typedef

Typedef is defining a new type for use in your code, like a shorthand.

    typedef typename MyBase::value_type value_type;
    value_type v; // We can now use v

Typename here is letting the compiler know that value_type is a type and not a static member of MyBase

If `MyBase` is dependent on a template parameter, then typename is necessary

The typename is saying that Mybase::value_type is the name of type so the typedef can reley on that fact.

In order to parse a C++ program, the compiler needs to know whether certain names are types or not. The following example demonstrates that: `t * f;` How should this be parsed ?
Some names denote types or templates. In general, whenever a name is encountered it is necessary to determine whether that name denotes one of these entities before continuing to parse the program that contains it. The process that determines this is called name lookup. So there has to be a way to tell the compiler that certain names are types and that certain names aren't.

If `t::x` is a dependent name, then we need to prefix it by typename to tell the compiler to parse it in a certain way

A dependent-name is any name that directly, or indirectly, depends on a template-parameter.

> A name used in a template declaration or definition and that is dependent on a template-parameter is assumed not to name a type unless the applicable name lookup finds a type name or the name is qualified by the keyword typename

There are certain contexts in C++ where the compiler must explicitly be told how to treat a name, and all these contexts have one thing in common; they depend on at least one template-parameter

## Typename & Typedef (selon Microsoft via leur [documentation](https://docs.microsoft.com/fr-fr/cpp/cpp/aliases-and-typedefs-cpp?view=vs-2019))

Contrairement aux déclarations de classe, de struct, d' Unionet d' enum , les déclarations typedef n’introduisent pas de nouveaux types, elles introduisent de nouveaux noms pour les types existants.
