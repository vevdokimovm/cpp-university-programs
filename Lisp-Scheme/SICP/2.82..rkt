#lang racket

(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))
      (if proc
          (apply proc (map contents args))
          (let ((items (coercion-to-types args type-tags)))
            (if items
                (apply-generic op items)
                (error "Невозможно привести -- APPLY-GENERIC" (list op args))))))))

(define (coercion-to-types args types)
  (if (null? types)
      #f
      (let ((type (car types))
            (result (coercion-type args type)))
        (if result
            result
            (coercion-to-types args (cdr types))))))

(define (coercion-type args type)
  (let* ((element (car args))
         (coercion (get (tag element) type)))
    (cond ((null? args) '())
          (coercion (cons (if (eq? (tag element) type) element (coercion element))
                          (coercion-type (cdr args) type)))
          (else #f))))