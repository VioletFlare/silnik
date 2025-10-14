import typescript from '@rollup/plugin-typescript';
import sourcemaps from 'rollup-plugin-sourcemaps';
import dts from "rollup-plugin-dts";
import del from "rollup-plugin-delete";

export default [
    {
        input: 'src/index.ts',
        output: [
            {
                file: 'index.cjs',
                format: 'cjs'
            },
            {
                file: 'index.mjs',
                format: 'esm'
            }
        ],
        plugins: [
            typescript({ sourceMap: true, inlineSources: true }),
            sourcemaps()
        ]
    },
    {
        input: "src/types/index.d.ts",
        output: [{
            file: "index.d.ts",
            format: "es",
            plugins: []
        }],
        plugins: [      
            dts(),
            del({ targets: "dist/types", hook: "buildEnd" })
        ],
    }
]