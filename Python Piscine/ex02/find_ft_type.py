def all_thing_is_obj(object: any) -> int:
    # 객체가 특정 클래스(또는 자료형)에 속하는지 확인하는 내장 함수 isinstance(object, class_or_tuple)
    if isinstance(object, list):
        print(f"List : {type(object)}")
    elif isinstance(object, tuple):
        print(f"Tuple : {type(object)}")
    elif isinstance(object, set):
        print(f"Set : {type(object)}")
    elif isinstance(object, dict):
        print(f"Dict : {type(object)}")
    elif isinstance(object, str):
        print(f"{object} is in the kitchen : {type(object)}")
    else:
        print("Type not found")
    return 42