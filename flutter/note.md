# Flutter

## 설치하기
1. 아래 명령줄을 사용하여 *설정상태*를 확인할 수 있다.   
```sh
flutter doctor
```

### Window

### Andorid

## 실행하기

### VSCode
1. *Extension* 에서 Dart Code 의 *Flutter* 확장 플러그인을 설치하도록 하자.  
  
2. vscode 의 palette (ctrl/cmd + shift + p) 에서 *Select Device* 를 선택하여 장치를 세팅해 주자.

3. lib/main.dart 파일에서 *Run Without Debugging* 을 통해 실행하면 된다.   

## 내장 클래스
### StatelessWidget
> 위젯을 만들 때 사용하는 기본 클래스중 하나. 이 위젯은 상태를 가지지 않으며, 생성 시에 주어진 데이터에 기반하여 화면을 그리는 역할.  
> 즉, 상태가 변경되지 않는 불변(immutable) 위젯을 정의할 때 사용


- 불변성 (Immutability): StatelessWidget은 상태를 가지지 않으므로, 위젯의 속성은 한 번 설정된 후 변경되지 않습니다. 즉, 위젯의 외관이나 동작이 변경되지 않습니다.

- 퍼포먼스 (Performance): 상태가 없으므로, StatelessWidget은 상태가 있는 위젯보다 성능이 좋을 수 있습니다. 위젯의 상태가 변경되지 않기 때문에, 위젯이 재구성(rebuild)될 때 더 간단하고 빠릅니다.

- 사용 시점: StatelessWidget은 주로 화면에 표시할 내용이 고정되어 있고, 사용자 상호작용에 의해 변경되지 않는 경우에 사용합니다.

### StatefulWidget
> 동적인 상태를 가지는 위젯을 만들 때 사용

1. 핵심은 *setState* 이다.

```dart
import 'dart:math';
import 'package:flutter/material.dart';
int mynum = 1;
class MyNumber extends StatefulWidget {
    const MyNumber({ super.key });
    @override
    State<MyNumber> createState() {
        return _MyNumberState();
    }
}
class _MyNumberState extends State<MyNumber> {
    void setMyNum() {
        setState(() {
            mynum = Random().nextInt(1000) + 1;
        });
    }
    @override
    Widget build(context) {
        return Column(
            children: [
                TextButton(
                    onPressed: setMyNum, 
                    style: TextButton.styleFrom(
                        foregroundColor: Colors.red,
                        textStyle: const TextStyle(
                            fontSize: 28,
                        )
                    ),
                    child: Text('$mynum')
                )
            ],
        );
    }
}
```
### BoxDecoration
> Container 위젯이나 다른 위젯의 배경을 꾸미기 위해 사용하는 클래스, 다양한 시각적 효과를 적용 할 수 있다.

1. gradient
```dart
BoxDecoration(
    gradient: LinearGradient(
        colors: [ 
            Color.fromARGB(255, 26, 2, 80),
            Color.fromARGB(255, 45, 7, 98),
        ],
        begin: Alignment.topLeft,
        end: Alignment.bottomRight
    )
),
```
2. image
```dart
BoxDecoration(
    image: DecorationImage(
        image: AssetImage('assets/logo.jpg'),
        fit: BoxFit.cover,
    ),
)
```
### Text
```dart
Text(
    'Hello World!',
        style: TextStyle(
        color: Colors.red,
        fontSize: 18,
    )
),
```

## 커스텀 위젯 만들기
```dart
import 'package:flutter/material.dart';
void main() {
    runApp(
        MaterialApp(
            home: GradientScaffold()
        )
    );
}
class GradientScaffold extends StatelessWidget {
    @override
    Widget build(BuildContext context) {
        return Scaffold(
            body: GradientContainer() 
        );
    }
}
class GradientContainer extends StatelessWidget {
    // const GradientContainer({ super.key }) 한줄로 처리할수도 있음!
    GradientContainer({ Key? key }): super(key: key) {
        print('Init::GradientContainer');
    }
    @override
    Widget build(BuildContext context) {
        return Container(
            decoration: const BoxDecoration(
                gradient: LinearGradient(
                    colors: [ 
                        Color.fromARGB(255, 26, 2, 80),
                        Color.fromARGB(255, 45, 7, 98),
                    ],
                    begin: Alignment.topLeft,
                    end: Alignment.bottomRight
                )
            ),
            child: const Center(
                child: Text(
                    'Hello World!',
                        style: TextStyle(
                            color: Colors.white,
                            fontSize: 28,
                        )
                ),
            )
        );
    }
}
```
## 다른 소스코드 호출하기
1. 상대경로 방식
```dart
import './gradient-container.dart';
```
2. 절대경로 방식
```dart
import 'package:프로젝트명/gradient-container.dart';
```

## 짜증나는 const
> Flutter에서는 const를 활용하여 위젯의 성능을 최적화 할 수 있다.   
> const를 사용하면 Flutter가 동일한 위젯 인스턴스를 재사용함

그 외 일반적인 의미는 다음과 같다.  
    
- 상수 값: 컴파일 타임에 결정되며, 런타임 동안 변경되지 않음
- 불면 객체: 객체의 속성이나 값이 변경되지 않으며, 동일한 값의 객체는 메모리에서 동일한 인스턴스를 재사용됨
  
**const**는 컴파일 타임 상수를 정의하며, 객체를 불변으로 만듦.