{
  "targets": [
    {
      "target_name": "primesieve",
      "sources": [ "primesieve.cpp"],
      "cflags": ["-Wall", "-std=c++11"],
      'xcode_settings': {
        'OTHER_CFLAGS': [
          '-std=c++11'
        ],
      },
      "include_dirs": [
        "include", "../primesieve-5.4.2/include"
      ],
      'libraries': [
         '-lprimesieve', '-L../primesieve-5.4.2/.libs/libprimesieve.so.4'
      ]
    }
  ]
}