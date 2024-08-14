// Uses Declarative syntax to run commands inside a container.
@Library('StateOS_Bachelor_Thesis')_

node {
    kubernetes {
        // Rather than inline YAML, in a multibranch Pipeline you could use: yamlFile 'jenkins-pod.yaml'
        // Or, to avoid YAML:
        // containerTemplate {
        //     name 'shell'
        //     image 'ubuntu'
        //     command 'sleep'
        //     args 'infinity'
        // }
        yaml '''
            apiVersion: v1
            kind: Pod
            spec:
            containers:
            - name: shell
                image: artifactory-04.boschdevcloud.com/docker-virtual/ubuntu:latest
                command:
                - sleep
                args:
                - infinity
            imagePullSecrets:
            - name: gds-secret-dockerreg-cs27-artifactory-04
            '''
        defaultContainer 'shell'
        retries 2
    }
    new Pipeline_(this).pipeline_build(true,true,false,true)
}

