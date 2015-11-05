{
  "targets": [
    {
      "target_name": "primesieve",
      "sources": [ "primesieve.cpp"],
      "cflags": ["-Wall", "-std=c++11"],
      'xcode_settings': {
        'OTHER_CFLAGS': [
          '-std=c++11',
        ],
        'GCC_ENABLE_CPP_EXCEPTIONS': 'YES'
      },
      "include_dirs": [
        "include", "deps/primesieve-5.4.2/include"
      ],
      'libraries': [
        '-lprimesieve'
      ]
    }
  ]
}