def NULL_not_found(object: any) -> int:
    if object is None:
        print(f"Nothing: None {type(object)}")
        return 0
    # NaN은 자기 자신과도 같지 않음
    elif isinstance(object, float) and object != object:
        print(f"Cheese: nan {type(object)}")
        return 0
    elif object == 0 and not isinstance(object, bool):
        print(f"Zero: 0 {type(object)}")
        return 0
    elif object == '':
        print(f"Empty: {type(object)}")
        return 0
    elif object is False:
        print(f"Fake: {object} {type(object)}")
        return 0
    else:
        print("Type not Found")
        return 1